# $NetBSD: Makefile,v 1.3 2011/08/14 12:38:56 obache Exp $
#

DISTNAME=	PPIx-EditorTools-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	editors perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPIx/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AZ/AZAWAWI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-EditorTools/
COMMENT=	Utility methods and base class for manipulating Perl via PPI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+= p5-Test-Differences>=0.4801:../../devel/p5-Test-Differences

DEPENDS+=	p5-Class-XSAccessor>=1.02:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI

PERL5_PACKLIST=		auto/PPIx/EditorTools/.packlist
PERL5_MODULE_TYPE=	Module::Install

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
