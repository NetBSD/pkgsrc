# $NetBSD: Makefile,v 1.1 2015/04/30 04:27:04 mef Exp $

DISTNAME=	Test-RequiresInternet-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mallen/Test-RequiresInternet/
COMMENT=	Test::RequiresInternet - Easily test network connectivity
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Test/RequiresInternet/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
