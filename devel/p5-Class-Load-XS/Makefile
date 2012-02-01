# $NetBSD: Makefile,v 1.2 2012/02/01 19:17:15 rhaen Exp $

DISTNAME=	Class-Load-XS-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Load-XS/
COMMENT=	XS implementation of parts of Class::Load
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.11:../../devel/p5-Class-Load

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Load/XS/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
