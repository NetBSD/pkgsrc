# $NetBSD: Makefile,v 1.8 2017/06/05 14:23:42 ryoon Exp $
#

DISTNAME=		Test-Dir-1.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Dir/
COMMENT=		Test directory attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Dir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
