# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:30 jlam Exp $

DISTNAME=	Chart-2.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chartgrp/
COMMENT=	Perl5 charting library

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD

PERL5_PACKLIST=	auto/Chart/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
