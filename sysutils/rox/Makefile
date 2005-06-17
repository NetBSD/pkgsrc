# $NetBSD: Makefile,v 1.25 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=	rox-2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

DEPENDS+=	shared-mime-info>=0.9:../../databases/shared-mime-info

CONFLICTS=	rox-base-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Filer/src
DIST_SUBDIR=	rox

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		APP_DIR=${WRKDIR}/${DISTNAME}/ROX-Filer
CONFIGURE_ARGS+=	--enable-rox --with-platform=${OPSYS}-${MACHINE_ARCH}

INSTALLATION_DIRS=	bin libexec/rox man/man1

post-patch:
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" < ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

post-build:
	${MV} ${WRKSRC} ${WRKDIR}/${DISTNAME}/src

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/rox
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/ROX-Filer	\
			${PREFIX}/libexec/rox
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/Choices/MIME-types
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/Choices/MIME-types/*	\
			${PREFIX}/share/rox/Choices/MIME-types
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/ROX-Filer
	cd ${WRKDIR}/${DISTNAME}/ROX-Filer && ${PAX} -rw . ${PREFIX}/share/rox/ROX-Filer
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" <				\
		${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun > 		\
		${PREFIX}/share/rox/ROX-Filer/AppRun
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/rox.xml	\
			${PREFIX}/share/mime/packages

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
