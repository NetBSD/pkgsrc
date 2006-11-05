# $NetBSD: Makefile,v 1.6 2006/11/05 17:49:34 joerg Exp $
#

DISTNAME=		Class-MakeMethods-1.01
PKGNAME=		p5-${DISTNAME}0 # developer uses three-digit versions
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MakeMethods/
COMMENT=		Getter/setter OO method maker for class elements

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MakeMethods/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
