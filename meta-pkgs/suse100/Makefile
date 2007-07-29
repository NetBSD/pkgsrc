# $NetBSD: Makefile,v 1.8 2007/07/29 05:19:35 jlam Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	aspell base compat cups expat fontconfig	\
			freetype2 gdk-pixbuf glx gtk gtk2 jpeg locale	\
			motif openssl png slang tiff vmware x11 xml2
EMUL_PKG_FMT=		plain

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
