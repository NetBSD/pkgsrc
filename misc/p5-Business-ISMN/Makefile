# $NetBSD: Makefile,v 1.1 2015/01/30 13:46:36 mef Exp $
#

DISTNAME=	Business-ISMN-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/B/BD/BDFOY/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bdfoy/Business-ISMN-1.11/lib/ISMN.pm
COMMENT=	Perl5 module to work with ISMN:s
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tie-Cycle>=0:../../devel/p5-Tie-Cycle

PERL5_PACKLIST=	auto/Business/ISMN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
