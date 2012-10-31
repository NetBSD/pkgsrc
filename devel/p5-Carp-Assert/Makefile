# $NetBSD: Makefile,v 1.13 2012/10/31 11:17:44 asau Exp $

DISTNAME=	Carp-Assert-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5cpa
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/search?dist=Carp-Assert
COMMENT=	Executable comments like the ANSI C library assert.h

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
