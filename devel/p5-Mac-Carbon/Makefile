# $NetBSD: Makefile,v 1.11 2013/05/31 12:40:29 wiz Exp $
#

DISTNAME=	Mac-Carbon-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mac-Carbon/
COMMENT=	Carbon API for perl on Mac OS X

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-powerpc

USE_LANGUAGES=	c c++

PERL5_PACKLIST=	auto/Mac/Carbon/.packlist

BUILDLINK_PASSTHRU_DIRS+=	/Developer/Headers/FlatCarbon

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
