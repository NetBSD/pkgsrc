# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 03:50:23 abs Exp $

DISTNAME=	UNIVERSAL-can-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CH/CHROMATIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-can/
COMMENT=	Hack around people calling UNIVERSAL::can() as a function

DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Simple>=0.60:../../devel/p5-Test-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/UNIVERSAL/can/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
