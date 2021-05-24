# $NetBSD: Makefile,v 1.21 2021/05/24 19:50:16 wiz Exp $

DISTNAME=	Class-Data-Accessor-0.04004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Data-Accessor
COMMENT=	Inheritable and overridable class and instance data accessors
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Class/Data/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
