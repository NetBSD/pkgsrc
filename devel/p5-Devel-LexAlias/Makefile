# $NetBSD: Makefile,v 1.20 2023/07/06 09:39:02 wiz Exp $

DISTNAME=	Devel-LexAlias-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-LexAlias
COMMENT=	Alias lexical variables
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Caller>=0.04:../../devel/p5-Devel-Caller

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/LexAlias/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
