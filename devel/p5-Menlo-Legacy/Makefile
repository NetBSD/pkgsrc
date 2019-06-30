# $NetBSD: Makefile,v 1.4 2019/06/30 20:15:17 nia Exp $

DISTNAME=	Menlo-Legacy-1.9022
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Menlo-Legacy
COMMENT=	Legacy internal and client support for Menlo
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Menlo-[0-9]*:../../devel/p5-Menlo

PERL5_PACKLIST=	auto/Menlo/Legacy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
