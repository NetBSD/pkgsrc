# $NetBSD: Makefile,v 1.3 2010/08/29 13:01:48 seb Exp $
#

DISTNAME=	Test-TCP-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-TCP/
COMMENT=	Perl 5 module to test TCP program
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/TCP/.packlist

DEPENDS+=	p5-Test-SharedFork>=0.12:../../devel/p5-Test-SharedFork

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
