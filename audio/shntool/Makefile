# $NetBSD: Makefile,v 1.6 2009/07/14 18:56:00 rafal Exp $
#

DISTNAME=	shntool-3.0.10
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shntool/
COMMENT=	Lossless audio compressor wrapper tool

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

# could also support: "WV" (is this not wav?), OFR, LPAC and APE.
DEPENDS+=	shorten>=3.6.0:../../audio/shorten
DEPENDS+=	flac>=1.1.0:../../audio/flac
DEPENDS+=	sox>=12.17.4:../../audio/sox

.include "../../mk/bsd.pkg.mk"
