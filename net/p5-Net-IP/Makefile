# $NetBSD: Makefile,v 1.2 2004/02/23 16:00:18 minskim Exp $
#

DISTNAME=	Net-IP-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~manu/Net-IP-1.20/
COMMENT=	Perl extension for manipulating IPv4/IPv6 addresses

DEPENDS+=	p5-Math-BigInteger-[0-9]*:../../math/p5-Math-BigInteger

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
