# $NetBSD: Makefile,v 1.18 2021/05/24 19:51:53 wiz Exp $

DISTNAME=	Tie-Cache-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Cache
COMMENT=	LRU Cache in Memory
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/Cache/.packlist

REPLACE_PERL=	*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
