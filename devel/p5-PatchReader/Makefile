# $NetBSD: Makefile,v 1.1.1.1 2004/11/03 20:40:43 adrianp Exp $

DISTNAME=	PatchReader-0.9.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JK/JKEISER/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jkeiser/${DISTNAME}
COMMENT=	Utilities to read and manipulate patches and CVS

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PatchReader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
