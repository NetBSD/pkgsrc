# $NetBSD: Makefile,v 1.2 2014/02/21 13:32:58 fhajny Exp $

DISTNAME=	Convert-Binary-C-0.76
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-Binary-C
COMMENT=	Binary Data Conversion using C Types
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=	auto/Convert/Binary/C/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
