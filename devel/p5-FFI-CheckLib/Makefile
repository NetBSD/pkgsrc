# $NetBSD: Makefile,v 1.17 2023/07/06 09:39:08 wiz Exp $

DISTNAME=	FFI-CheckLib-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FFI-CheckLib
COMMENT=	Check that a library is available for FFI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Test-Exit-[0-9]*:../../devel/p5-Test-Exit

PERL5_PACKLIST=		auto/FFI/CheckLib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
