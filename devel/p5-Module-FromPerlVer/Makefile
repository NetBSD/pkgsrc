# $NetBSD: Makefile,v 1.7 2018/03/18 08:44:00 wiz Exp $

DISTNAME=		Module-FromPerlVer-0.005007
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Module-FromPerlVer/
COMMENT=		Install modules compatible with the running perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
# TEST_DEPENDS
BUILD_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
# 3 test failures in 0.004002

PERL5_PACKLIST=		auto/Module/FromPerlVer/.packlist
USE_TOOLS+=		perl

REPLACE_PERL+=		t/bin/make-version-dir
REPLACE_PERL+=		t/bin/make-sandbox-dir
REPLACE_PERL+=		t/bin/make-tests
REPLACE_SH+=		t/bin/make-sandbox-tarball

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
