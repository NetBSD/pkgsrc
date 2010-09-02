# $NetBSD: Makefile,v 1.13 2010/09/02 19:11:28 sno Exp $

DISTNAME=	Class-Accessor-Grouped-0.09005
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Grouped/
COMMENT=	Lets you build groups of accessors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name

# For test target
BUILD_DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Accessor/Grouped/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
