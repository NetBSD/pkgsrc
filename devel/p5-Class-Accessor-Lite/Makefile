# $NetBSD: Makefile,v 1.18 2023/07/06 09:38:44 wiz Exp $

DISTNAME=	Class-Accessor-Lite-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-Accessor-Lite
COMMENT=	Minimalistic variant of Class::Accessor
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Accessor/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
