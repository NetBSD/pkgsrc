# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:22 jlam Exp $

DISTNAME=	Class-Data-Inheritable-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/MSCHWERN/Class-Data-Inheritable-0.02/
COMMENT=	Inheritable, overridable class data

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
