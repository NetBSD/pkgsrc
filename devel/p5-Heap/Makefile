# $NetBSD: Makefile,v 1.4 2003/07/17 21:32:29 grant Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl collection of routines for managing a heap data structure

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
