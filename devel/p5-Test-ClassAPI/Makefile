# $NetBSD: Makefile,v 1.6 2007/06/08 08:41:24 wiz Exp $

DISTNAME=		Test-ClassAPI-1.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-ClassAPI/
COMMENT=		Provide basic first-pass API testing for large class trees

DEPENDS+=		p5-Class-Inspector>=1.12:../../devel/p5-Class-Inspector
DEPENDS+=		p5-Config-Tiny>=2.0:../../devel/p5-Config-Tiny
DEPENDS+=		p5-Params-Util-[0-9]*:../../devel/p5-Params-Util

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Test/ClassAPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
