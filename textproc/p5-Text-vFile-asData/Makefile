# $NetBSD: Makefile,v 1.16 2016/06/08 19:24:41 wiz Exp $

DISTNAME=	Text-vFile-asData-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-vFile-asData/
COMMENT=	Parse vFile formatted files into data structures

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained

PERL5_PACKLIST=	auto/Text/vFile/asData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
