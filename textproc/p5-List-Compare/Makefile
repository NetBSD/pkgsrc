# $NetBSD: Makefile,v 1.20 2022/06/28 11:36:19 wiz Exp $

DISTNAME=		List-Compare-0.55
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/List-Compare
COMMENT=		Compare elements of two or more lists
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/List/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
