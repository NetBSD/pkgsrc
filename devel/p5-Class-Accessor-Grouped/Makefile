# $NetBSD: Makefile,v 1.8 2009/10/12 12:01:22 rhaen Exp $

DISTNAME=	Class-Accessor-Grouped-0.09001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RK/RKITOVER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Grouped/
COMMENT=	Lets you build groups of accessors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor

# For test target
BUILD_DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Accessor/Grouped/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
