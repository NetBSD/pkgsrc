# $NetBSD: Makefile,v 1.8 2006/03/04 21:29:19 jlam Exp $

DISTNAME=	Class-Data-Inheritable-0.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Data-Inheritable/
COMMENT=	Inheritable, overridable class data

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
