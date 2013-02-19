# $NetBSD: Makefile,v 1.10 2013/02/19 19:04:33 kleink Exp $

DISTNAME=	Text-vFile-asData-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tva
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-vFile-asData/
COMMENT=	Parse vFile formatted files into data structures

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained

PERL5_PACKLIST=	auto/Text/vFile/asData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
