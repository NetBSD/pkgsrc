# $NetBSD: Makefile,v 1.1 2013/07/03 07:22:45 sno Exp $

DISTNAME=	Test-FailWarnings-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-FailWarnings/
COMMENT=	Add test failures if warnings are caught
LICENSE=	apache-2.0

BUILD_DEPENDS+=	p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Test/FailWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
