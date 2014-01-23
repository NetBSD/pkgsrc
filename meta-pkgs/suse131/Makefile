# $NetBSD: Makefile,v 1.3 2014/01/23 06:51:17 obache Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa aspell base compat cyrus-sasl cups curl dbus-glib \
			expat fontconfig freetype2 glib2 glx gtk2 jpeg krb5 \
			libffi libjson libsigc++2 libsndfile libssh libwrap \
			locale motif nspr nss openldap openssl pulseaudio png \
			qt4 slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
