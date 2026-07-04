# $NetBSD: Makefile,v 1.10 2026/07/04 06:25:04 wiz Exp $

DISTNAME=	shntool-3.0.10
PKGREVISION=	1
CATEGORIES=	audio archivers
#MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.etree.org/shnutils/shntool/
COMMENT=	Lossless audio compressor wrapper tool
LICENSE=	gnu-gpl-v2

# could also support: "WV" (is this not wav?), OFR, LPAC and APE.
DEPENDS+=	shorten>=3.6.0:../../audio/shorten
DEPENDS+=	flac>=1.1.0:../../audio/flac
DEPENDS+=	sox_ng>=12.17.4:../../audio/sox_ng

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
