# $NetBSD: Makefile,v 1.16 2011/08/14 12:26:09 obache Exp $

DISTNAME=	Heap-0.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Heap/
COMMENT=	Perl collection of routines for managing a heap data structure

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
