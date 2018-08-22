# $NetBSD: Makefile,v 1.24 2018/08/22 09:43:45 wiz Exp $

DISTNAME=	Class-Trigger-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Trigger/
COMMENT=	Mixin to add/call inheritable triggers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy>=0.02:../../devel/p5-IO-stringy

PERL5_PACKLIST=		auto/Class/Trigger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
