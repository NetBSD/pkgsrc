# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:13 joerg Exp $
#

DISTNAME=	Class-Fields-0.203
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5clf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Fields/
COMMENT=	Set of modules to operate with class fields and members access

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/Fields/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
