# $NetBSD: Makefile,v 1.3 2014/05/09 08:29:39 wen Exp $
#

DISTNAME=		Test-File-1.36
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-File/
COMMENT=		Test file attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
