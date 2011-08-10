# $NetBSD: Makefile,v 1.16 2011/08/10 04:05:44 adam Exp $

DISTNAME=	Class-Container-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5ccr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Container/
COMMENT=	Glues object frameworks together transparently
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Params-Validate>=0.23:../../devel/p5-Params-Validate
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=		# none
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Container/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
