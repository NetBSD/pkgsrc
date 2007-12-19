# $NetBSD: Makefile,v 1.14 2007/12/19 12:27:27 rillig Exp $
#

DISTNAME=	fxtv-capture-1.1
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package including all packages to capture video with bktr(4)

DEPENDS+=	sox>=12.17.1:../../audio/sox
DEPENDS+=	mpegaudio>=3.9:../../audio/mpegaudio
DEPENDS+=	fxtv>=1.03nb1:../../multimedia/fxtv
DEPENDS+=	mpeg_encode-[0-9]*:../../multimedia/mpeg_encode
DEPENDS+=	mjpegtools>=1.8.0nb1:../../multimedia/mjpegtools

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
