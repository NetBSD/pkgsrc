# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:25 jlam Exp $
#

DISTNAME=		Test-Taint-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Taint/
COMMENT=		Tools to test taintedness

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Test/Taint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
