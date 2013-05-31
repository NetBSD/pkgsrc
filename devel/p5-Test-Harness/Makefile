# $NetBSD: Makefile,v 1.42 2013/05/31 12:40:48 wiz Exp $
#

DISTNAME=	Test-Harness-3.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Harness/
COMMENT=	Run Perl standard test scripts with statistics
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
