# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:19 jlam Exp $

DISTNAME=	Attribute-Handlers-0.78
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ah
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Attribute-Handlers/
COMMENT=	Simpler definition of attribute handlers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Attribute/Handlers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
