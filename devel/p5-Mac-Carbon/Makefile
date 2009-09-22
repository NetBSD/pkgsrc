# $NetBSD: Makefile,v 1.3 2009/09/22 20:56:53 sno Exp $
#

DISTNAME=	Mac-Carbon-0.80
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mac-Carbon/
COMMENT=	Carbon API for perl on Mac OS X

ONLY_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PERL5_PACKLIST=	auto/Mac/Carbon/.packlist

BUILDLINK_PASSTHRU_DIRS+=	/Developer/Headers/FlatCarbon

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
