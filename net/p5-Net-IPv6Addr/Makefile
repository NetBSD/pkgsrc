# $NetBSD: Makefile,v 1.26 2021/09/12 07:30:40 wen Exp $

DISTNAME=	Net-IPv6Addr-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TMONROE/Net-IPv6Addr-0.2
COMMENT=	Check the validity of IPv6 addresses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Base85>=0.2:../../math/p5-Math-Base85
DEPENDS+=	p5-Math-BigInt>=1.999813:../../math/p5-Math-BigInt

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
