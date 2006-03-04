# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:24 jlam Exp $

DISTNAME=		Test-ClassAPI-1.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-ClassAPI/
COMMENT=		Provide basic first-pass API testing for large class trees

DEPENDS+=		p5-Class-Inspector>=1.06:../../devel/p5-Class-Inspector
DEPENDS+=		p5-Config-Tiny>=2.0:../../devel/p5-Config-Tiny

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Test/ClassAPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
