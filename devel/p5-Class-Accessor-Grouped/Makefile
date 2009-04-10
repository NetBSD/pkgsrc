# $NetBSD: Makefile,v 1.4 2009/04/10 09:46:18 abs Exp $

DISTNAME=	Class-Accessor-Grouped-0.08003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Grouped/
COMMENT=	Lets you build groups of accessors

DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Accessor/Grouped/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
