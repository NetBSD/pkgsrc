# $NetBSD: Makefile,v 1.1 2016/07/25 08:50:03 wen Exp $

DISTNAME=	Tree-R-0.072
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-R/
COMMENT=	Perl extension for the Rtree data structure and algorithms
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Tree/R/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
