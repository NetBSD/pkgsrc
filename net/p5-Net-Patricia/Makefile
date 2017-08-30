# $NetBSD: Makefile,v 1.24 2017/06/05 14:24:20 ryoon Exp $
#

DISTNAME=	Net-Patricia-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tm@core.io
HOMEPAGE=	http://search.cpan.org/dist/Net-Patricia/
COMMENT=	Patricia Trie perl module for fast IP address lookups
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-CIDR-Lite>=0.20:../../net/p5-Net-CIDR-Lite

PERL5_PACKLIST=		auto/Net/Patricia/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
