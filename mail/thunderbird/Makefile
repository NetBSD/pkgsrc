# $NetBSD: Makefile,v 1.4 2004/06/24 23:09:55 taya Exp $

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.7
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-${MOZ_VER}-source
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client

CONFIGURE_ENV+=	MOZ_THUNDERBIRD=1
MAKE_ENV+=	MOZ_THUNDERBIRD=1

CONFIGURE_ARGS+=	--enable-extensions=wallet,spellcheck,xmlextras

pre-install:
	${CP} -r ${WRKSRC}/dist/bin/defaults/profile/extensions \
							${WRKSRC}/dist/bin
	${MV} ${WRKSRC}/dist/bin/extensions/installed-extensions.txt \
		${WRKSRC}/dist/bin/extensions/installed-extensions-processed.txt

.include "../../www/mozilla/Makefile.common"
