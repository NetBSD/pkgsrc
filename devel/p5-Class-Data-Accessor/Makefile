# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:22:57 abs Exp $

DISTNAME=	Class-Data-Accessor-0.04002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Data-Accessor/
COMMENT=	Inheritable and overridable class and instance data accessors

PERL5_MODULE_TYPE=	MakeMaker

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Data/Accessor/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
