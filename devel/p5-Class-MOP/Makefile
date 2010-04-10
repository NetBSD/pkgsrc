# $NetBSD: Makefile,v 1.33 2010/04/10 07:11:51 seb Exp $
#

DISTNAME=	Class-MOP-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-MOP/
COMMENT=	Perl 5 module providing a meta object protocol
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-MRO-Compat>=0.05:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny>=0.02:../../devel/p5-Try-Tiny

# Only for test target
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER # t/050_scala_style_mixin_composition.t
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output # t/310_inline_structor.t
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace # t/312_anon_class_leak.t

USE_LANGUAGES=	c
MAKE_JOBS_SAFE= no

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/MOP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
