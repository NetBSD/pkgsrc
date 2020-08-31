# $NetBSD: Makefile,v 1.4 2020/08/31 18:07:45 wiz Exp $

DISTNAME=	Data-Binary-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Binary
COMMENT=	Simple detection of binary versus text in strings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Data/Binary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
