# $NetBSD: Makefile,v 1.6 2009/09/12 18:12:28 sno Exp $
#

DISTNAME=	B-Utils-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Utils/
COMMENT=	Perl 5 module providing op tree manipulation helper functions
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/B/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
