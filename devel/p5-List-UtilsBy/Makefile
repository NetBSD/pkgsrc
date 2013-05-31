# $NetBSD: Makefile,v 1.4 2013/05/31 12:40:27 wiz Exp $
#

DISTNAME=	List-UtilsBy-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-UtilsBy/
COMMENT=	Higher-order list utility functions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGE=	# empty
PERL5_PACKLIST=	auto/List/UtilsBy/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
