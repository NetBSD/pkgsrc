# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:25 jlam Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl collection of routines for managing a heap data structure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
