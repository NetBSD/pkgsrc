# $NetBSD: Makefile,v 1.3 2015/09/26 01:14:20 kamil Exp $

DISTNAME=	suse-${SUSE_VERSION}
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa aspell base compat cups expat fontconfig freetype2
EMUL_MODULES.linux+=	gc glx gstreamer gtk2 jpeg krb5 libsigc++2 locale motif
EMUL_MODULES.linux+=	openssl png qt4 slang sqlite3 tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
