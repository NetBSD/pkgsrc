# $NetBSD: Makefile,v 1.25 2005/06/16 06:57:42 jlam Exp $

PSI_VERSION=	0.9.3
DISTNAME=	psi-${PSI_VERSION}
PKGREVISION=	# empty
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANG_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# XXX uses internal bsd.pkg.mk variable
FETCH_BEFORE_ARGS+=	${FETCH_OUTPUT_ARGS} "${DISTDIR}/${DIST_SUBDIR}/$$bfile"

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

DEPENDS+=	qca-tls>=1.0:../../security/qca-tls

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS= --prefix="${PREFIX}" --qtdir="${QTDIR}"
CONFIGURE_ARGS+=	--with-qca-inc="${BUILDLINK_PREFIX.qca}/include" \
			--with-qca-lib="${BUILDLINK_PREFIX.qca}/lib"

LANG_FILES=	psi_zh.qm psi_nl.qm psi_sk.qm psi_fr.qm psi_cs.qm	\
		psi_de.qm psi_et.qm psi_pl.qm psi_mk.qm psi_el.qm	\
		psi_es.qm psi_ru.qm psi_vi.qm

.for l in ${LANG_FILES}
SITES_${l}=	http://psi.affinix.com/?version=${PSI_VERSION}&file=
.endfor

INSTALLATION_DIRS=	bin

# XXX the psiwidgets.so symlink is somewhat ugly, but without that
# uic doesn't find the built plug-in and generates sources without
# proper psiwidgets #include's. This should eventually be fixed in
# qmake template.
post-configure:
	${SED} \
	-e 's:^CHK_DIR_EXISTS *= *$$:CHK_DIR_EXISTS=test -d:' \
	-e "s:^MKDIR *= *$$:MKDIR=${MKDIR}:" \
	-e "s:/bin/true:${TRUE}:" < ${WRKSRC}/Makefile \
		> ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile
	cd ${WRKSRC}/libpsi/psiwidgets && (	\
		${QTDIR}/bin/qmake psiwidgets.pro -o Makefile; \
		${SED} -e 's,-rpath.*$$,-rpath "${QTDIR}/lib",' < Makefile > Makefile.new; \
		${MV} Makefile.new Makefile; \
		${LN} -s .libs/libpsiwidgets.so psiwidgets.so; \
	)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/psi
	cd ${WRKSRC} && \
	${CP} -f -pR iconsets sound certs README COPYING ${PREFIX}/share/psi/
	for f in ${LANG_FILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$f \
			 ${PREFIX}/share/psi/; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/psi ${PREFIX}/bin/psi

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
