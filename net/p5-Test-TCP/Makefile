# $NetBSD: Makefile,v 1.9 2012/10/23 17:18:55 asau Exp $
#

DISTNAME=	Test-TCP-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TCP/
COMMENT=	Perl 5 module to test TCP program
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-SharedFork>=0.19:../../devel/p5-Test-SharedFork

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/TCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
