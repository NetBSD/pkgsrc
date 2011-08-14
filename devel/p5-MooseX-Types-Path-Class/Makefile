# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:23 obache Exp $
#

DISTNAME=	MooseX-Types-Path-Class-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Path-Class/
COMMENT=	A Path::Class type library for Moose

DEPENDS+=	p5-Class-MOP>=0:../../devel/p5-Class-MOP
DEPENDS+=	p5-Moose>=0.39:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class
# For tests (but introduce a circular dependency for devel/p5-MooseX-Getopt)
#BUILD_DEPENDS+=	p5-MooseX-Getopt>=0:../../devel/p5-MooseX-Getopt

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/Path/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
