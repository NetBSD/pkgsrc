# $NetBSD: Makefile,v 1.1.1.1 2004/11/30 11:31:36 wiz Exp $

DISTNAME=	Class-Inner-0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/search?query=Class%3A%3AInner&mode=dist
COMMENT=	Perlish implementation of Java like inner classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Inner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
