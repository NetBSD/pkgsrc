# $NetBSD: Makefile,v 1.23 2009/06/07 11:30:15 seb Exp $
#

DISTNAME=	Class-MOP-0.85
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-MOP/
COMMENT=	Perl 5 module providing a meta object protocol
LICENSE=	artistic-2.0

DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

# Only for test target
BUILD_DEPENDS+=	p5-PathTools-[0-9]*:../../devel/p5-PathTools
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception

USE_LANGUAGES=	c
MAKE_JOBS_SAFE= no

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/MOP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
