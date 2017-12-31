# $NetBSD: Makefile,v 1.17 2017/12/31 13:39:16 wiz Exp $

DISTNAME=	File-Copy-Recursive-0.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Copy-Recursive/
COMMENT=	Perl extension for recursively copying files and directories
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Copy/Recursive/.packlist

DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-Path-Iter-[0-9]*:../../devel/p5-Path-Iter
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-File-[0-9]*:../../devel/p5-Test-File
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
