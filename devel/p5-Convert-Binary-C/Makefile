# $NetBSD: Makefile,v 1.11 2019/08/11 13:19:08 wiz Exp $

DISTNAME=	Convert-Binary-C-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-Binary-C
COMMENT=	Binary Data Conversion using C Types
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=	auto/Convert/Binary/C/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
