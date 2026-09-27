# $NetBSD: Makefile,v 1.1 2026/09/27 12:59:08 wen Exp $

DISTNAME=		Test2-Plugin-Cover-0.000030
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-Cover
COMMENT=		Fast and Minimal file coverage info
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Path-Tiny>=0.048:../../filesystems/p5-Path-Tiny

PERL5_PACKLIST=		auto/Test2/Plugin/Cover/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
