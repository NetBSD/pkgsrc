# $NetBSD: Makefile,v 1.23 2022/06/28 11:36:37 wiz Exp $

DISTNAME=	Text-vFile-asData-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-vFile-asData
COMMENT=	Parse vFile formatted files into data structures

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained

PERL5_PACKLIST=	auto/Text/vFile/asData/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
