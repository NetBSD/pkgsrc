# $NetBSD: Makefile,v 1.8 2017/06/05 14:22:46 ryoon Exp $

DISTNAME=	Convert-Binary-C-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
