# $NetBSD: Makefile,v 1.17 2022/06/28 11:32:00 wiz Exp $

DISTNAME=	Class-Accessor-Lite-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-Accessor-Lite
COMMENT=	Minimalistic variant of Class::Accessor
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Accessor/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
