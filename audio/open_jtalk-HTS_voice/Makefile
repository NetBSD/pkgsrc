# $NetBSD: Makefile,v 1.1 2020/06/16 13:40:24 ryoon Exp $

DISTNAME=	hts_voice_nitech_jp_atr503_m001-1.05
PKGNAME=	${DISTNAME:S/hts_voice_nitech_jp_atr503_m001-/open_jtalk-HTS_voice-/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-jtalk/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://open-jtalk.sourceforge.net/
COMMENT=	NIT ATR503 M001 Japanese speech database (male)
#LICENSE=	cc-by-v3.0

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/open_jtalk/voices

do-install:
	${INSTALL_DATA} ${WRKSRC}/nitech_jp_atr503_m001.htsvoice \
		${DESTDIR}${PREFIX}/share/open_jtalk/voices
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/open_jtalk/voices/nitech_jp_atr503_m001.htsvoice.COPYING

.include "../../mk/bsd.pkg.mk"
