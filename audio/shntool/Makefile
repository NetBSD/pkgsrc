# $NetBSD: Makefile,v 1.7 2012/10/02 23:48:08 asau Exp $
#

DISTNAME=	shntool-3.0.10
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shntool/
COMMENT=	Lossless audio compressor wrapper tool

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

# could also support: "WV" (is this not wav?), OFR, LPAC and APE.
DEPENDS+=	shorten>=3.6.0:../../audio/shorten
DEPENDS+=	flac>=1.1.0:../../audio/flac
DEPENDS+=	sox>=12.17.4:../../audio/sox

.include "../../mk/bsd.pkg.mk"
