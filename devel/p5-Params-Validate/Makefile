# $NetBSD: Makefile,v 1.31 2008/10/12 17:39:41 abs Exp $

DISTNAME=	Params-Validate-0.91
PKGREVISION=	1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Validate/
COMMENT=	Validate method/function parameters

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{p5-Attribute-Handlers>=0.76,perl>=5.10.0}:../../devel/p5-Attribute-Handlers

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
