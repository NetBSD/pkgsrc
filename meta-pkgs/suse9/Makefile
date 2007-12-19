# $NetBSD: Makefile,v 1.9 2007/12/19 12:27:30 rillig Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

.include "../../emulators/suse91_linux/Makefile.common"

META_PACKAGE=	yes

EMUL_MODULES.linux=	aspell base compat expat fontconfig freetype2	\
			gdk-pixbuf glx gtk gtk2 jpeg locale motif png	\
			slang tiff x11

.if ${EMUL_PLATFORM} == "linux-i386"
EMUL_MODULES.linux+=	vmware
.endif

EMUL_PKG_FMT=		plain

.include "../../mk/bsd.pkg.mk"
