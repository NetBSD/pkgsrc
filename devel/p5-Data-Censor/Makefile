# $NetBSD: Makefile,v 1.2 2026/07/16 19:02:10 wiz Exp $

DISTNAME=	Data-Censor-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Censor
COMMENT=	Censor sensitive stuff in a data structure
LICENSE=	artistic-2.0

DEPENDS+=	p5-Ref-Util>=0:../../devel/p5-Ref-Util

PERL5_PACKLIST=		auto/Data/Censor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
