# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:33 wiz Exp $

DISTNAME=	Tie-Cache-LRU-Expires-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Cache-LRU-Expires
COMMENT=	Extends Tie::Cache::LRU with expiring
LICENSE=	artistic

DEPENDS+=	p5-Tie-Cache-LRU-[0-9]*:../../devel/p5-Tie-Cache-LRU

PERL5_PACKLIST=	auto/Tie/Cache/LRU/Expires/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
