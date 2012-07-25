# $NetBSD: Makefile,v 1.8 2012/07/25 15:33:46 wen Exp $

DISTNAME=	Test-SharedFork-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-SharedFork/
COMMENT=	Perl 5 module to make forking test
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/SharedFork/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
