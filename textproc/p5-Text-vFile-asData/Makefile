# $NetBSD: Makefile,v 1.6 2010/09/06 11:03:06 wiz Exp $

DISTNAME=	Text-vFile-asData-0.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tva
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-vFile-asData/
COMMENT=	Parse vFile formatted files into data structures

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained

PERL5_PACKLIST=	auto/Text/vFile/asData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
