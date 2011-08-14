# $NetBSD: Makefile,v 1.2 2011/08/14 12:26:14 obache Exp $
#

DISTNAME=	LEOCHARRE-Dir-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LE/LEOCHARRE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LEOCHARRE-Dir/
COMMENT=	Subs for general directory needs
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/LEOCHARRE/Dir/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
