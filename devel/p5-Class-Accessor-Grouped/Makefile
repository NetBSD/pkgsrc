# $NetBSD: Makefile,v 1.6 2009/06/13 06:46:44 rillig Exp $

DISTNAME=	Class-Accessor-Grouped-0.08003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Grouped/
COMMENT=	Lets you build groups of accessors

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Accessor/Grouped/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
