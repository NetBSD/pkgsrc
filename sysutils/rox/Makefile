# $NetBSD: Makefile,v 1.98 2020/06/02 08:24:48 adam Exp $
#

DISTNAME=	rox-filer-2.11
PKGNAME=	rox-2.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X
LICENSE=	gnu-gpl-v2

CONFLICTS=	rox-base-[0-9]*

DIST_SUBDIR=	rox

USE_TOOLS+=		pax pkg-config
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin libexec/rox ${PKGMANDIR}/man1 \
			share/Choices share/mime/packages \
			share/rox/ROX-Filer

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	ROX-Filer/src/choices.c
SUBST_FILES.path+=	ROX-Filer/src/type.c
SUBST_FILES.path+=	ROX-Filer/src/xdgmime.c
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		bin
SUBST_MESSAGE.bin=	Fixing binary path.
SUBST_STAGE.bin=	pre-configure
SUBST_FILES.bin=	ROX-Filer/AppRun
SUBST_SED.bin=		-e 's,BIN="$$APP_DIR,BIN="${PREFIX}/libexec/rox,g'

BUILD_TARGET=		ROX-Filer
CONFIGURE_DIRS=		ROX-Filer/src
CONFIGURE_SCRIPT=	./configure.tmp
LIBS.SunOS+=		-lm
LDFLAGS.DragonFly+=	-lm
LIBS.Linux+=		-ldl -lm

post-patch:
	${MV} ${WRKSRC}/ROX-Filer/src/configure ${WRKSRC}/ROX-Filer/src/${CONFIGURE_SCRIPT}

post-build:
	@${ECHO} "#!/bin/sh" >> ${WRKDIR}/rox
	@${ECHO} ${PREFIX}"/share/rox/ROX-Filer/AppRun \"\$$@\"" >> ${WRKDIR}/rox

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ROX-Filer/ROX-Filer ${DESTDIR}${PREFIX}/libexec/rox
	cd ${WRKSRC}/Choices && pax -rw . ${DESTDIR}${PREFIX}/share/Choices
	cd ${WRKSRC}/ROX-Filer && pax -rw	\
		-s ',^\./ROX-Filer$$,,' -s ',^\./ROX-Filer/.*,,'	\
		-s ',^\./ROX-Filer.dbg$$,,' -s ',^\./ROX-Filer.dbg/.*,,'\
		-s ',^\./src$$,,' -s ',^\./src/.*,,'	\
		. ${DESTDIR}${PREFIX}/share/rox/ROX-Filer
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/rox.xml ${DESTDIR}${PREFIX}/share/mime/packages
	${INSTALL_SCRIPT} ${WRKDIR}/rox ${DESTDIR}${PREFIX}/bin

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/dlopen.buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
