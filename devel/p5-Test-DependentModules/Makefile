# $NetBSD: Makefile,v 1.1 2015/05/09 14:20:15 mef Exp $

DISTNAME=	Test-DependentModules-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/
COMMENT=	Test all modules which depend on your module
LICENSE=	artistic-2.0

BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Module-Build-Tiny-[0-9]*:../../devel/p5-Module-Build-Tiny
BUILD_DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
BUILD_DEPENDS+=	p5-IO-Handle-Util-[0-9]*:../../devel/p5-IO-Handle-Util
BUILD_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
BUILD_DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
BUILD_DEPENDS+=	p5-MetaCPAN-Client-[0-9]*:../../devel/p5-MetaCPAN-Client
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
BUILD_DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive

PERL5_PACKLIST=	auto/Test/DependentModules/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
