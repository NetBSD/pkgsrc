# $NetBSD: Makefile,v 1.1.1.1 2008/10/12 17:26:15 abs Exp $
#

DISTNAME=	Devel-Declare-0.001011
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Declare/
COMMENT=	Declarator magic for perl

DEPENDS+=     p5-Scalar-List-Utils>0:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=     p5-Test-Simple>0:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Devel/Declare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
