# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:30 jschauma Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl collection of routines for managing a heap data structure

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
