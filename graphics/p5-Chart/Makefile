# $NetBSD: Makefile,v 1.1.1.1 2004/11/03 15:27:16 adrianp Exp $

DISTNAME=	Chart-2.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chartgrp/
COMMENT=	Perl5 charting library

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Chart/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
