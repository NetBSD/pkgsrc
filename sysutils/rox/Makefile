# $NetBSD: Makefile,v 1.32 2006/01/29 14:14:40 rxg Exp $
#

DISTNAME=	rox-2.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

CONFLICTS=	rox-base-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}
DIST_SUBDIR=	rox

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	libexec/rox share/Choices share/rox/ROX-Filer

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	ROX-Filer/AppRun
SUBST_FILES.path+=	ROX-Filer/src/choices.c
SUBST_FILES.path+=	ROX-Filer/src/type.c
SUBST_FILES.path+=	ROX-Filer/src/xdgmime.c
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		bin
SUBST_MESSAGE.bin=	Fixing binary path.
SUBST_STAGE.bin=	post-patch
SUBST_FILES.bin=	ROX-Filer/AppRun
SUBST_SED.bin=		-e 's,BIN="$$APP_DIR,BIN="${PREFIX}/libexec/rox,g'

BUILD_TARGET=		ROX-Filer
CONFIGURE_DIRS=		ROX-Filer/src
CONFIGURE_SCRIPT=	configure.tmp

post-patch:
	${MV} ${WRKSRC}/ROX-Filer/src/configure ${WRKSRC}/ROX-Filer/src/${CONFIGURE_SCRIPT}

post-build:
	@${ECHO} "#!/bin/sh" >> ${WRKDIR}/rox
	@${ECHO} "${PREFIX}/share/rox/ROX-Filer/AppRun \"$$""@\"" >> ${WRKDIR}/rox

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ROX-Filer/ROX-Filer ${PREFIX}/libexec/rox
	cd ${WRKSRC}/Choices && ${PAX} -rw . ${PREFIX}/share/Choices
	cd ${WRKSRC}/ROX-Filer && ${PAX} -rw	\
		-s ',^\./ROX-Filer$$,,' -s ',^\./ROX-Filer/.*,,'	\
		-s ',^\./ROX-Filer.dbg$$,,' -s ',^\./ROX-Filer.dbg/.*,,'\
		-s ',^\./src$$,,' -s ',^\./src/.*,,'	\
		. ${PREFIX}/share/rox/ROX-Filer
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/rox.xml ${PREFIX}/share/mime/packages
	${INSTALL_SCRIPT} ${WRKDIR}/rox ${PREFIX}/bin

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
