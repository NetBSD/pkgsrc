# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:19 jlam Exp $

DISTNAME=	Class-Inner-0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/search?query=Class%3A%3AInner&mode=dist
COMMENT=	Perlish implementation of Java like inner classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Class/Inner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
