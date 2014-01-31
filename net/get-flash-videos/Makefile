# $NetBSD: Makefile,v 1.6 2014/01/31 11:21:18 dsainty Exp $

DISTNAME=	${GHACCOUNT}-${GHNAME}-${GHDESCRIBE}-g${GHCOMMIT}
PKGNAME=	${GHNAME}-0.0.${GHDATE}
GHNAME=		get-flash-videos

# git describe + GHVERSION from the last commit + GHCOMMIT from the tar.
GHACCOUNT=	monsieurvideo
GHDATE=		20140129
GHDESCRIBE=	v1.22-586
GHVERSION=	d6e4f43fbb858dd0ba94a2c9431f40a9af13dbfe
GHCOMMIT=	d6e4f43

CATEGORIES=	net
MASTER_SITES=	https://github.com/${GHACCOUNT}/${GHNAME}/tarball/${GHVERSION}/

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://code.google.com/p/get-flash-videos/
COMMENT=	Tool for using various Flash-based video hosting sites
LICENSE=	apache-2.0

DEPENDS+=	p5-Data-AMF-[0-9]*:../../comms/p5-Data-AMF
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Module-Find-[0-9]*:../../devel/p5-Module-Find
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	rtmpdump-[0-9]*:../../net/rtmpdump

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}/${GHACCOUNT}-${GHNAME}-${GHCOMMIT}

PERL5_PACKLIST=	auto/App/get_flash_videos/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
