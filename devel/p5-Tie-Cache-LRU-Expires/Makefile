# $NetBSD: Makefile,v 1.10 2016/06/08 19:23:43 wiz Exp $

DISTNAME=	Tie-Cache-LRU-Expires-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Cache-LRU-Expires/
COMMENT=	Extends Tie::Cache::LRU with expiring
LICENSE=	artistic

DEPENDS+=	p5-Tie-Cache-LRU-[0-9]*:../../devel/p5-Tie-Cache-LRU

PERL5_PACKLIST=	auto/Tie/Cache/LRU/Expires/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
