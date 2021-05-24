# $NetBSD: Makefile,v 1.31 2021/05/24 19:50:14 wiz Exp $

DISTNAME=	Class-Accessor-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-Accessor
COMMENT=	Automated accessor generation
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
