# $NetBSD: Makefile,v 1.19 2009/04/12 10:39:01 he Exp $

DISTNAME=	Attribute-Handlers-0.83
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ah
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Attribute-Handlers/
COMMENT=	Simpler definition of attribute handlers

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Attribute/Handlers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
