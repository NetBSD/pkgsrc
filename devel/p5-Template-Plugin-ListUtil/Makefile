# $NetBSD: Makefile,v 1.13 2018/08/22 09:44:41 wiz Exp $
#

DISTNAME=	Template-Plugin-ListUtil-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-ListUtil/
COMMENT=	List::Util functions for TT
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

#DEPENDS+=	{perl>=5.8,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Template-Plugin-VMethods>=0.02:../../devel/p5-Template-Plugin-VMethods
DEPENDS+=	p5-Template-Toolkit>=2.06:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Plugin/ListUtil/.packlist
PERL5_MODULE_TYPE=	Module::Build

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
