# $NetBSD: Makefile,v 1.26 2024/11/16 12:03:50 wiz Exp $

DISTNAME=	Class-MakeMethods-1.01
PKGNAME=	p5-${DISTNAME}0 # developer uses three-digit versions
PKGREVISION=	17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-MakeMethods
COMMENT=	Getter/setter OO method maker for class elements
LICENSE=	${PERL5_LICENSE}

USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		auto/Class/MakeMethods/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
