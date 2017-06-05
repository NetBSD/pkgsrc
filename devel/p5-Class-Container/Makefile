# $NetBSD: Makefile,v 1.26 2017/06/05 14:22:41 ryoon Exp $

DISTNAME=	Class-Container-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Container/
COMMENT=	Glues object frameworks together transparently
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Validate>=0.23:../../devel/p5-Params-Validate
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=		# none
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Container/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
