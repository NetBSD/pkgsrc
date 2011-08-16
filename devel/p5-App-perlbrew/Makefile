# $NetBSD: Makefile,v 1.7 2011/08/16 21:11:30 wiz Exp $

DISTNAME=	App-perlbrew-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-perlbrew/
COMMENT=	Manage perl installations in your $$HOME
LICENSE=	mit

DEPENDS+=	p5-Devel-PatchPerl>=0.46:../../devel/p5-Devel-PatchPerl
DEPENDS+=	p5-File-Path-Tiny>=0.1:../../devel/p5-File-Path-Tiny
DEPENDS+=	p5-HTTP-Lite>=2.2:../../www/p5-HTTP-Lite

# actually, only TEST_DEPENDS
BUILD_DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
BUILD_DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
BUILD_DEPENDS+=	p5-Test-Spec-[0-9]*:../../devel/p5-Test-Spec

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/App/perlbrew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
