# $NetBSD: Makefile,v 1.8 2017/06/05 14:23:38 ryoon Exp $
#

DISTNAME=	Term-Animation-2.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/K/KB/KBAUCOM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kbaucom/Term-Animation/
COMMENT=	ASCII sprite animation package
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Curses>=1.06:../../devel/p5-Curses

PERL5_PACKLIST=	auto/Term/Animation/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
