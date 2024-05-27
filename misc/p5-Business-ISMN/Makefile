# $NetBSD: Makefile,v 1.16 2024/05/27 07:58:25 wen Exp $

DISTNAME=	Business-ISMN-1.204
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Business-ISMN
COMMENT=	Perl5 module to work with ISMNs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tie-Cycle>=0:../../devel/p5-Tie-Cycle

PERL5_PACKLIST=	auto/Business/ISMN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
