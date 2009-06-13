# $NetBSD: Makefile,v 1.4 2009/06/13 06:46:44 rillig Exp $

DISTNAME=	Class-C3-XS-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-C3-XS/
COMMENT=	XS speedups for Class::C3
LICENSE=	artistic-2.0

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Class/C3/XS/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
