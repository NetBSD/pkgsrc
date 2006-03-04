# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:19 jlam Exp $

DISTNAME=	Class-ObjectTemplate-0.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cot
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-ObjectTemplate/
COMMENT=	Perl extension for optimized template builder base class

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/ObjectTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
