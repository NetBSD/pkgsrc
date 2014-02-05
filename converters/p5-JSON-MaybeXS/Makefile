# $NetBSD: Makefile,v 1.1.1.1 2014/02/05 21:43:11 abs Exp $

DISTNAME=	JSON-MaybeXS-1.001000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-MaybeXS/
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-PP>=2.27202:../../converters/p5-JSON-PP

PERL5_PACKLIST=		auto/JSON/MaybeXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
