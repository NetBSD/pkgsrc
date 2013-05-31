# $NetBSD: Makefile,v 1.14 2013/05/31 12:40:08 wiz Exp $

DISTNAME=	Class-Inner-0.200001
PKGNAME=	p5-${DISTNAME:S/200001/200.001/}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Inner/
COMMENT=	Perlish implementation of Java like inner classes
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Inner/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
