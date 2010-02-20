# $NetBSD: Makefile,v 1.1.1.1 2010/02/20 11:28:49 seb Exp $
#

DISTNAME=	Test-TCP-0.16
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

DEPENDS+=	p5-Test-SharedFork>=0.09:../../devel/p5-Test-SharedFork
# For test target
BUILD_DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
