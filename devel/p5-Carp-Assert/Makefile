# $NetBSD: Makefile,v 1.14 2013/05/31 12:40:06 wiz Exp $

DISTNAME=	Carp-Assert-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
