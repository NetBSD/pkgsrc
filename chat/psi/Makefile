# $NetBSD: Makefile,v 1.33 2006/01/24 07:31:58 wiz Exp $

PSI_VERSION=	0.10
DISTNAME=	psi-${PSI_VERSION}
PKGREVISION=	1
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
USE_LANGUAGES+=	c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qca-inc=${BUILDLINK_PREFIX.qca:Q}/include
CONFIGURE_ARGS+=	--with-qca-lib=${BUILDLINK_PREFIX.qca:Q}/lib

LANG_FILES=	psi_zh.qm psi_nl.qm psi_sk.qm psi_fr.qm psi_cs.qm	\
		psi_de.qm psi_et.qm psi_pl.qm psi_mk.qm psi_el.qm	\
		psi_es.qm psi_ru.qm psi_vi.qm

.for l in ${LANG_FILES}
SITES_${l}=	http://psi-im.org/download?page=download&version=${PSI_VERSION}&lang_id=
.endfor

INSTALLATION_DIRS=	bin share/psi share/doc/psi

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
	cd ${WRKSRC}/libpsi/psiwidgets && ( ${SETENV} ${CONFIGURE_ENV}	\
		${QTDIR}/bin/qmake psiwidgets.pro -o Makefile; \
		${SED} -e 's,-rpath.*$$,-rpath "${QTDIR}/lib",' \
			< Makefile > Makefile.new; \
		${MV} Makefile.new Makefile; \
		${LN} -s .libs/libpsiwidgets.so psiwidgets.so; \
	)

do-install:
.for f in iconsets sound certs
	${INSTALL_DATA_DIR} ${PREFIX}/share/psi/${f}
	cd ${WRKSRC}/${f} && ${PAX} -rwppm . ${PREFIX}/share/psi/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/psi
.for f in ${LANG_FILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${PREFIX}/share/psi
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/psi ${PREFIX}/bin/psi

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
