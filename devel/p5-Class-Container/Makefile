# $NetBSD: Makefile,v 1.12 2008/04/06 15:34:22 heinz Exp $

DISTNAME=	Class-Container-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ccr
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Container/
COMMENT=	Glues object frameworks together transparently

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Params-Validate>=0.23:../../devel/p5-Params-Validate
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=		# none
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Container/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
