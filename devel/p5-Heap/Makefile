# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl collection of routines for managing a heap data structure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
