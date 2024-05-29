# $NetBSD: Makefile,v 1.7 2024/05/29 16:31:17 adam Exp $

DISTNAME=	TheUnarchiverSource
PKGNAME=	unarchiver-3.10 # See ${WRKSRC}/Info.plist
PKGREVISION=	6
CATEGORIES=	archivers
MASTER_SITES=	https://cdn.theunarchiver.com/downloads/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://theunarchiver.com/command-line
COMMENT=	Command-line tools for The Unarchiver
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/XADMaster
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

NO_CONFIGURE=		yes
GNUSTEP_MAKEFILE=	Makefile.linux
MAKE_FLAGS+=		CC=${CC} OBJCC=${OBJC} CXX=${CXX}

# Fix build with clang. See
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230627
.include "../../devel/gnustep-make/gnustep.mk"
.if empty(PKG_OPTIONS:Mfragile)
BUILDLINK_TRANSFORM+=	rm:-DGNU_RUNTIME=1
BUILDLINK_TRANSFORM+=	rm:-fgnu-runtime
.endif

# Also remove -isystem /usr/include/GNUstep. Our GNUstep is not there.
BUILDLINK_TRANSFORM+=	rm:-isystem rm:/usr/include/GNUstep

INSTALLATION_DIRS+= bin ${PKGMANDIR}/man1 share/bash-completion/completions
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsar ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unar ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/Extra/lsar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/Extra/unar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/Extra/lsar.bash_completion ${DESTDIR}${PREFIX}/share/bash-completion/completions/lsar
	${INSTALL_DATA} ${WRKDIR}/Extra/unar.bash_completion ${DESTDIR}${PREFIX}/share/bash-completion/completions/unar

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
