# $NetBSD: Makefile,v 1.5 2017/06/05 14:24:14 ryoon Exp $

DISTNAME=	Business-ISMN-1.131
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/B/BD/BDFOY/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bdfoy/Business-ISMN/
COMMENT=	Perl5 module to work with ISMNs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tie-Cycle>=0:../../devel/p5-Tie-Cycle

PERL5_PACKLIST=	auto/Business/ISMN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
