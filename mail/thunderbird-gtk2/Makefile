# $NetBSD: Makefile,v 1.2 2004/05/08 04:38:08 taya Exp $

MOZILLA=	thunderbird-gtk2
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.6
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client

CONFIGURE_ENV+=	MOZ_THUNDERBIRD=1
MAKE_ENV+=	MOZ_THUNDERBIRD=1

DISTINFO_FILE=	${.CURDIR}/../../mail/thunderbird/distinfo
PATCHDIR=	${.CURDIR}/../../mail/thunderbird/patches

CONFIGURE_ARGS+=	--enable-extensions=wallet,spellcheck,xmlextras
MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include "../../www/mozilla/Makefile.common"
