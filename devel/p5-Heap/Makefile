# $NetBSD: Makefile,v 1.5 2004/04/25 03:10:53 minskim Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl collection of routines for managing a heap data structure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
