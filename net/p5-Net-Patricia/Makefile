# $NetBSD: Makefile,v 1.4 2019/06/30 20:16:31 nia Exp $
#

DISTNAME=	Net-Patricia-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Patricia
COMMENT=	Patricia Trie perl module for fast IP address lookups
LICENSE=	gnu-gpl-v2 AND 2-clause-bsd

DEPENDS+=	p5-Net-CIDR-Lite>=0.20:../../net/p5-Net-CIDR-Lite
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6

PERL5_PACKLIST=		auto/Net/Patricia/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
