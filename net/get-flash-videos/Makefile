# $NetBSD: Makefile,v 1.4 2013/12/09 14:17:50 obache Exp $
#

DISTNAME=	${GHACCOUNT}-${GHNAME}-${GHDESCRIBE}-g${GHCOMMIT}
PKGNAME=	${GHNAME}-0.0.${GHDATE}
PKGREVISION=	1
GHNAME=		get-flash-videos

GHACCOUNT=	monsieurvideo
GHDATE=		20121204
GHDESCRIBE=	v1.22-398
GHVERSION=	d74c9f6e0119f6340b027b1b97b6603704040922
GHCOMMIT=	d74c9f6

PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GHACCOUNT}/${GHNAME}/tarball/${GHVERSION}/

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://code.google.com/p/get-flash-videos/
COMMENT=	Tool for using various Flash-based video hosting sites
LICENSE=	apache-2.0

FETCH_USING=	curl # For https:

DEPENDS+=	p5-Data-AMF-[0-9]*:../../comms/p5-Data-AMF
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	rtmpdump-[0-9]*:../../net/rtmpdump

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}/${GHACCOUNT}-${GHNAME}-${GHCOMMIT}

PERL5_PACKLIST=	auto/App/get_flash_videos/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
