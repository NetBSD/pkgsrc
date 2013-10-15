# $NetBSD: Makefile,v 1.44 2013/10/15 02:33:08 wen Exp $
#

DISTNAME=	Test-Harness-3.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Harness/
COMMENT=	Run Perl standard test scripts with statistics
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
