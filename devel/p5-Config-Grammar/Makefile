# $NetBSD: Makefile,v 1.22 2025/07/04 08:45:27 wiz Exp $

DISTNAME=	Config-Grammar-1.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Grammar
COMMENT=	Grammar-based, user-friendly config parser
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Config/Grammar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
