# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:48 ryoon Exp $
#

DISTNAME=		Test-utf8-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-utf8/
COMMENT=		Handy UTF-8 tests
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/utf8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
