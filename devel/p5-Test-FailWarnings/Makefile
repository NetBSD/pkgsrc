# $NetBSD: Makefile,v 1.4 2015/01/28 02:13:03 mef Exp $

DISTNAME=	Test-FailWarnings-0.008
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
