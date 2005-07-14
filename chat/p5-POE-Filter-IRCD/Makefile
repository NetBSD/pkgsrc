# $NetBSD: Makefile,v 1.1.1.1 2005/07/14 23:08:21 adrianp Exp $
#

DISTNAME=	POE-Filter-IRCD-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bingos/POE-Filter-IRCD-1.1/
COMMENT=	POE-based parser for the IRC protocol

DEPENDS+=	p5-POE>=0.17:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		auto/POE/Filter/IRCD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
