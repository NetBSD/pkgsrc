# $NetBSD: Makefile,v 1.30 2021/05/24 19:51:47 wiz Exp $

DISTNAME=	Test-Output-1.033
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Output
COMMENT=	Utilities to test STDOUT and STDERR messages
LICENSE=	artistic-2.0

DEPENDS+=	p5-Capture-Tiny>=0.17:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Test/Output/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
