# $NetBSD: Makefile,v 1.4 2005/08/06 06:19:08 jlam Exp $
#

DISTNAME=		Class-MakeMethods-1.01
PKGNAME=		p5-${DISTNAME}0 # developer uses three-digit versions
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MakeMethods/
COMMENT=		Getter/setter OO method maker for class elements

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MakeMethods/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
