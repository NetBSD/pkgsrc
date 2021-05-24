# $NetBSD: Makefile,v 1.24 2021/05/24 19:50:16 wiz Exp $

DISTNAME=	Class-Fields-0.204
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-Fields
COMMENT=	Set of modules to operate with class fields and members access
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Fields/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
