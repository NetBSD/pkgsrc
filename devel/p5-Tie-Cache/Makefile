# $NetBSD: Makefile,v 1.16 2019/08/11 13:20:40 wiz Exp $

DISTNAME=	Tie-Cache-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
