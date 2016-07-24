# $NetBSD: Makefile,v 1.22 2016/07/24 06:31:07 wen Exp $

DISTNAME=	Parse-CPAN-Meta-1.4422
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-CPAN-Meta/
COMMENT=	Perl5 module to parse META.yml and other similar CPAN metadata files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.21.5,p5-JSON-PP>=2.27300}:../../converters/p5-JSON-PP

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Parse/CPAN/Meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
