# $NetBSD: Makefile,v 1.2 2006/08/23 02:33:56 mrg Exp $
#

DISTNAME=	shntool-2.0.3
CATEGORIES=	audio archivers
MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.etree.org/shnutils/shntool/
COMMENT=	Lossless audio compressor wrapper tool

LICENSE=	no-commercial-use

GNU_CONFIGURE=	YES

# could also support: "WV" (is this not wav?), OFR, LPAC and APE.
DEPENDS+=	shorten>=3.6.0:../../audio/shorten
DEPENDS+=	flac>=1.1.0:../../audio/flac
DEPENDS+=	sox>=12.17.4:../../audio/sox

.include "../../mk/bsd.pkg.mk"
