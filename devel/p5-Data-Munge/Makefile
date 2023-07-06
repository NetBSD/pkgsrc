# $NetBSD: Makefile,v 1.18 2023/07/06 09:38:55 wiz Exp $

DISTNAME=	Data-Munge-0.097
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Munge
COMMENT=	Various utility functions
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/Data/Munge/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
