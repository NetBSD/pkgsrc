# $NetBSD: Makefile,v 1.2 2002/07/11 19:44:27 wiz Exp $
#

DISTNAME=	fxtv-capture-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@netbsd.org
COMMENT=	meta-package including all packages to capture video with bktr(4)

DEPENDS+=	sox>=12.17.1:../../audio/sox
DEPENDS+=	mpegaudio>=3.9:../../audio/mpegaudio
DEPENDS+=	fxtv>=1.03nb1:../../graphics/fxtv
DEPENDS+=	mpeg_encode-*:../../graphics/mpeg_encode
DEPENDS+=	mplex>=1.1:../../graphics/mplex

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
