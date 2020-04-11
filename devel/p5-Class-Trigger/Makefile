# $NetBSD: Makefile,v 1.27 2020/04/11 11:58:08 mef Exp $

DISTNAME=	Class-Trigger-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Trigger
COMMENT=	Mixin to add/call inheritable triggers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy>=0.02:../../devel/p5-IO-stringy

PERL5_PACKLIST=		auto/Class/Trigger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
