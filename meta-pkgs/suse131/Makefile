# $NetBSD: Makefile,v 1.5 2015/09/26 01:15:22 kamil Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa aspell base compat cyrus-sasl cups curl dbus-glib
EMUL_MODULES.linux+=	expat fontconfig freetype2 glib2 gc glx gtk2 jpeg krb5
EMUL_MODULES.linux+=	libffi libjson libsigc++2 libsndfile libssh libwrap
EMUL_MODULES.linux+=	locale motif nspr nss openldap openssl pulseaudio png
EMUL_MODULES.linux+=	qt4 slang tiff x11 xml2
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
