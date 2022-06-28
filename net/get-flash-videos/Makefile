# $NetBSD: Makefile,v 1.18 2022/06/28 11:35:00 wiz Exp $

DISTNAME=	get-flash-videos-0.0.20150331
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=monsieurvideo/}
GITHUB_TYPE=	tag
GITHUB_TAG=	eae1ac23fcc4a31ead78bfdd99c6faae3bde4ab3

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://github.com/monsieurvideo/get-flash-videos
COMMENT=	Tool for using various Flash-based video hosting sites
LICENSE=	apache-2.0

DEPENDS+=	p5-Crypt-Blowfish_PP-[0-9]*:../../security/p5-Crypt-Blowfish_PP
DEPENDS+=	p5-Data-AMF-[0-9]*:../../comms/p5-Data-AMF
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Module-Find-[0-9]*:../../devel/p5-Module-Find
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	rtmpdump-[0-9]*:../../net/rtmpdump

USE_TOOLS+=	perl:run

PERL5_PACKLIST=	auto/App/get_flash_videos/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
