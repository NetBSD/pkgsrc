# $NetBSD: Makefile,v 1.5 2012/09/11 09:02:04 sno Exp $
#

DISTNAME=	PPIx-EditorTools-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPIx/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SZ/SZABGAB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-EditorTools/
COMMENT=	Utility methods and base class for manipulating Perl via PPI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+= p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
BUILD_DEPENDS+= p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
BUILD_DEPENDS+= p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

DEPENDS+=	p5-Class-XSAccessor>=1.02:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-PPI>=1.215:../../devel/p5-PPI
DEPENDS+=	p5-Try-Tiny>=0.11:../../devel/p5-PPI

PERL5_PACKLIST=		auto/PPIx/EditorTools/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
