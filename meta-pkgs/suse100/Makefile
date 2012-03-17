# $NetBSD: Makefile,v 1.11 2012/03/17 06:08:15 obache Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	aspell base compat cups expat fontconfig	\
			freetype2 glx gtk jpeg locale			\
			motif openssl png slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
