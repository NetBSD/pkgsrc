# $NetBSD: Makefile,v 1.10 2019/07/01 21:35:43 nia Exp $
#

DISTNAME=	Term-Animation-2.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/K/KB/KBAUCOM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Animation
COMMENT=	ASCII sprite animation package
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Curses>=1.06:../../devel/p5-Curses

PERL5_PACKLIST=	auto/Term/Animation/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
