# $NetBSD: Makefile,v 1.1.1.1 2009/08/26 19:51:32 sno Exp $
#

DISTNAME=	Template-Plugin-ListUtil-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-ListUtil/
COMMENT=	List::Util functions for TT
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# empty

DEPENDS+=	{perl>=5.8,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Template-Plugin-VMethods:../../devel/p5-Template-Plugin-VMethods
DEPENDS+=	p5-Template-Toolkit>=2.06:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Plugin/ListUtil/.packlist
PERL5_MODULE_TYPE=	Module::Build

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
