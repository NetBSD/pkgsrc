# $NetBSD: Makefile,v 1.12 2012/03/19 09:14:52 obache Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	aspell base compat cups expat fontconfig	\
			freetype2 glx gtk2 jpeg locale			\
			motif openssl png slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
