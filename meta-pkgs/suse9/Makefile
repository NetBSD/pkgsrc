# $NetBSD: Makefile,v 1.8 2007/10/25 22:00:58 jlam Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

.include "../../emulators/suse91_linux/Makefile.common"

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

EMUL_MODULES.linux=	aspell base compat expat fontconfig freetype2	\
			gdk-pixbuf glx gtk gtk2 jpeg locale motif png	\
			slang tiff x11

.if ${EMUL_PLATFORM} == "linux-i386"
EMUL_MODULES.linux+=	vmware
.endif

EMUL_PKG_FMT=		plain

.include "../../mk/bsd.pkg.mk"
