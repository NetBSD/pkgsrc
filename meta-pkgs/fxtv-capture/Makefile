# $NetBSD: Makefile,v 1.8 2004/02/22 20:48:15 jmmv Exp $
#

DISTNAME=	fxtv-capture-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
COMMENT=	Meta-package including all packages to capture video with bktr(4)

DEPENDS+=	sox>=12.17.1:../../audio/sox
DEPENDS+=	mpegaudio>=3.9:../../audio/mpegaudio
DEPENDS+=	fxtv>=1.03nb1:../../multimedia/fxtv
DEPENDS+=	mpeg_encode-*:../../graphics/mpeg_encode
DEPENDS+=	mplex>=1.1:../../multimedia/mplex

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
