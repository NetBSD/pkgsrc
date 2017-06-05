# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:10 ryoon Exp $
#

DISTNAME=	List-Pairwise-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~tdrugeon/List-Pairwise/
COMMENT=	(Perl Module) List::Pairwise - map/grep arrays and hashes pairwise
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/List/Pairwise/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
