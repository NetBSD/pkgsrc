# $NetBSD: Makefile,v 1.41 2011/08/10 04:30:01 adam Exp $

DISTNAME=	Class-MOP-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-MOP/
COMMENT=	Perl 5 module providing a meta object protocol
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-List-MoreUtils>=0.12:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Package-DeprecationManager>=0.04:../../devel/p5-Package-DeprecationManager
DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny>=0.02:../../devel/p5-Try-Tiny

# Only for test target
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER # t/050_scala_style_mixin_composition.t
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace # t/312_anon_class_leak.t
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output # t/310_inline_structor.t
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

USE_LANGUAGES=		c
MAKE_JOBS_SAFE= 	no
PERL5_PACKLIST=		auto/Class/MOP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
