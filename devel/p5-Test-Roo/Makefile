# $NetBSD: Makefile,v 1.13 2023/06/06 12:41:07 riastradh Exp $

DISTNAME=		Test-Roo-1.004
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Roo
COMMENT=		Composable, reusable tests with roles and Moo
LICENSE=		apache-2.0

DEPENDS+=	p5-Moo>=1.000008:../../devel/p5-Moo
DEPENDS+=	p5-MooX-Types-MooseLike>=0:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-strictures>=0:../../devel/p5-strictures

TOOL_DEPENDS+=	p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Test/Roo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
