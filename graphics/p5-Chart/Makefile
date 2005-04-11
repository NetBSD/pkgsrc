# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:07 tv Exp $

DISTNAME=	Chart-2.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chartgrp/
COMMENT=	Perl5 charting library

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Chart/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
