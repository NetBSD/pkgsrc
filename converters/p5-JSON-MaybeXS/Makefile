# $NetBSD: Makefile,v 1.12 2016/06/08 19:22:20 wiz Exp $

DISTNAME=	JSON-MaybeXS-1.003005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-MaybeXS/
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.17.10,p5-JSON-PP>=2.27202}:../../converters/p5-JSON-PP
# actually test dependency
BUILD_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module

PERL5_PACKLIST=		auto/JSON/MaybeXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
