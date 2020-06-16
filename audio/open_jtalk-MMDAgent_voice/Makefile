# $NetBSD: Makefile,v 1.1 2020/06/16 13:41:20 ryoon Exp $

DISTNAME=	MMDAgent_Example-1.8
PKGNAME=	${DISTNAME:S/MMDAgent_Example-/open_jtalk-MMDAgent_voice-/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mmdagent/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.mmdagent.jp/
COMMENT=	Open JTalk voice data from MMDAgent project (female and male)
#LICENSE=	cc-by-v3.0 AND cmu_arctic

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/open_jtalk/voices

do-install:
	cd ${WRKSRC}/Voice && ${FIND} mei slt takumi \
		-type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/open_jtalk/voices

.include "../../mk/bsd.pkg.mk"
