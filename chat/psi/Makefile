# $NetBSD: Makefile,v 1.46 2006/09/02 20:21:54 rillig Exp $

PSI_VERSION=	0.10
DISTNAME=	psi-${PSI_VERSION}
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

DEPENDS+=	qca-tls>=1.0:../../security/qca-tls

DIST_SUBDIR=	${DISTNAME}-20060806-1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANG_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qca-inc=${BUILDLINK_PREFIX.qca:Q}/include
CONFIGURE_ARGS+=	--with-qca-lib=${BUILDLINK_PREFIX.qca:Q}/lib

LANG_FILES=	psi_bg.qm psi_ca.qm psi_eo.qm psi_es.qm psi_fr.qm	\
		psi_hu.qm psi_mk.qm psi_nl.qm psi_pl.qm psi_pt.qm	\
		psi_pt_BR.qm psi_sk.qm psi_sl.qm psi_vi.qm psi_zh.qm

.for l in ${LANG_FILES}
SITES.${l}=	http://psi-im.org/files/translation/${PSI_VERSION}/
.endfor

INSTALLATION_DIRS=	bin share/psi share/doc/psi

# XXX the psiwidgets.so symlink is somewhat ugly, but without that
# uic doesn't find the built plug-in and generates sources without
# proper psiwidgets #include's. This should eventually be fixed in
# qmake template.
post-configure:
	${SED} \
	-e 's:^CHK_DIR_EXISTS *= *$$:CHK_DIR_EXISTS=test -d:' \
	-e 's:^MKDIR *= *$$:MKDIR=${MKDIR}:' \
	-e "s:/bin/true:${TRUE}:" < ${WRKSRC}/Makefile \
		> ${WRKSRC}/Makefile.new
	${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile
	${ECHO} 'target.path=${QTDIR}/lib' \
		>> ${WRKSRC}/libpsi/psiwidgets/psiwidgets.pro
	${ECHO} 'QMAKE_UIC=${QTDIR}/bin/uic -L ../libpsi/psiwidgets/.libs' \
		>> ${WRKSRC}/src/src.pro
	cd ${WRKSRC}/libpsi/psiwidgets && ( ${SETENV} ${CONFIGURE_ENV}	\
		${QTDIR}/bin/qmake psiwidgets.pro -o Makefile; \
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
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
