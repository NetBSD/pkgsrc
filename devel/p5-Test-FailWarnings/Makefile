# $NetBSD: Makefile,v 1.16 2024/11/16 12:05:16 wiz Exp $

DISTNAME=	Test-FailWarnings-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-FailWarnings
COMMENT=	Add test failures if warnings are caught
LICENSE=	apache-2.0

TOOL_DEPENDS+=	p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Test/FailWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
