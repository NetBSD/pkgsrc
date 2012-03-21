# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:44:08 obache Exp $

DISTNAME=	suse-${SUSE_VERSION}
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa aspell base compat cups expat fontconfig	\
			freetype2 glx gtk2 jpeg krb5 libsigc++2 locale	\
			motif openssl png qt4 slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
