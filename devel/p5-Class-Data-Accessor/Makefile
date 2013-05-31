# $NetBSD: Makefile,v 1.11 2013/05/31 12:40:08 wiz Exp $

DISTNAME=	Class-Data-Accessor-0.04004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Data-Accessor/
COMMENT=	Inheritable and overridable class and instance data accessors
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Class/Data/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
