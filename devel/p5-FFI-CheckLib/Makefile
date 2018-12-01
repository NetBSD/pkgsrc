# $NetBSD: Makefile,v 1.6 2018/12/01 02:46:52 wen Exp $

DISTNAME=	FFI-CheckLib-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/FFI-CheckLib/
COMMENT=	Check that a library is available for FFI
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/FFI/CheckLib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
