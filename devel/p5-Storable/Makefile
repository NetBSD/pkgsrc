# $NetBSD: Makefile,v 1.28 2009/05/19 18:55:18 sno Exp $

DISTNAME=	Storable-2.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Storable/
COMMENT=	Perl extension module for persistent data storage

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
