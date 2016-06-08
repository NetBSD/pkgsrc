# $NetBSD: Makefile,v 1.11 2016/06/08 19:23:39 wiz Exp $
#

DISTNAME=		Test-POE-Client-TCP-1.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-POE-Client-TCP/
COMMENT=		POE Component providing TCP client services for test cases
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/POE/Client/TCP/.packlist

DEPENDS+=	p5-POE>=1.28:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
