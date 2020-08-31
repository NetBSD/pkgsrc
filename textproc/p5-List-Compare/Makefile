# $NetBSD: Makefile,v 1.17 2020/08/31 18:11:50 wiz Exp $
#

DISTNAME=		List-Compare-0.53
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/List-Compare
COMMENT=		Compare elements of two or more lists
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/List/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
