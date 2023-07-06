# $NetBSD: Makefile,v 1.31 2023/07/06 09:38:47 wiz Exp $

DISTNAME=	Class-ObjectTemplate-0.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-ObjectTemplate
COMMENT=	Perl extension for optimized template builder base class
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/ObjectTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
