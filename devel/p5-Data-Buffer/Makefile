# $NetBSD: Makefile,v 1.33 2024/11/16 12:03:57 wiz Exp $

DISTNAME=	Data-Buffer-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	mcr@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Buffer
COMMENT=	Perl5 module for low-level binary buffer

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Buffer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
