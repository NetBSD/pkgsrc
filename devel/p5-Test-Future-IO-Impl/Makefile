# $NetBSD: Makefile,v 1.2 2024/11/16 12:05:17 wiz Exp $

DISTNAME=	Test-Future-IO-Impl-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Future-IO-Impl
COMMENT=	Acceptance tests for Future::IO implementations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/Test/Future/IO/Impl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
