# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:12 obache Exp $

DISTNAME=	suse-${SUSE_VERSION}
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa aspell base compat cyrus-sasl cups curl expat \
			fontconfig freetype2 glx gtk2 jpeg krb5 libjson \
			libsigc++2 libsndfile libssh libwrap locale motif \
			openldap openssl pulseaudio png qt4 slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
