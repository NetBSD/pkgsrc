# $NetBSD: Makefile,v 1.9 2018/08/22 09:43:48 wiz Exp $

DISTNAME=	Convert-Binary-C-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
