# $NetBSD: Makefile,v 1.6 2019/02/21 04:27:29 tsutsui Exp $

DISTNAME=	suse-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

EMUL_MODULES.linux=	alsa
EMUL_MODULES.linux+=	aspell
EMUL_MODULES.linux+=	base
EMUL_MODULES.linux+=	binutils
EMUL_MODULES.linux+=	compat
EMUL_MODULES.linux+=	cups
EMUL_MODULES.linux+=	curl
EMUL_MODULES.linux+=	cyrus-sasl
EMUL_MODULES.linux+=	drm
EMUL_MODULES.linux+=	dbus
EMUL_MODULES.linux+=	dbus-glib
EMUL_MODULES.linux+=	expat
EMUL_MODULES.linux+=	fontconfig
EMUL_MODULES.linux+=	freetype2
EMUL_MODULES.linux+=	glib2
EMUL_MODULES.linux+=	gc
EMUL_MODULES.linux+=	glx
EMUL_MODULES.linux+=	gstreamer
EMUL_MODULES.linux+=	gtk2
EMUL_MODULES.linux+=	jpeg
EMUL_MODULES.linux+=	krb5
EMUL_MODULES.linux+=	libSDL
EMUL_MODULES.linux+=	libaudiofile
EMUL_MODULES.linux+=	libesd
EMUL_MODULES.linux+=	libffi
EMUL_MODULES.linux+=	libidn
EMUL_MODULES.linux+=	libjson
EMUL_MODULES.linux+=	libsigc++2
EMUL_MODULES.linux+=	libsndfile
EMUL_MODULES.linux+=	libssh
EMUL_MODULES.linux+=	libwrap
EMUL_MODULES.linux+=	locale
EMUL_MODULES.linux+=	lsb
EMUL_MODULES.linux+=	motif
EMUL_MODULES.linux+=	nspr
EMUL_MODULES.linux+=	nss
EMUL_MODULES.linux+=	openldap
EMUL_MODULES.linux+=	openssl
EMUL_MODULES.linux+=	png
EMUL_MODULES.linux+=	pulseaudio
EMUL_MODULES.linux+=	qt4
EMUL_MODULES.linux+=	slang
EMUL_MODULES.linux+=	tiff
EMUL_MODULES.linux+=	webp
EMUL_MODULES.linux+=	x11
EMUL_MODULES.linux+=	xml2
EMUL_MODULES.linux+=	xslt
EMUL_PKG_FMT=		plain

META_PACKAGE=	yes

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
