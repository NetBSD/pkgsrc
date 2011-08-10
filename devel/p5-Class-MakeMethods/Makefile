# $NetBSD: Makefile,v 1.10 2011/08/10 04:21:29 adam Exp $

DISTNAME=	Class-MakeMethods-1.01
PKGNAME=	p5-${DISTNAME}0 # developer uses three-digit versions
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-MakeMethods/
COMMENT=	Getter/setter OO method maker for class elements
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MakeMethods/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
