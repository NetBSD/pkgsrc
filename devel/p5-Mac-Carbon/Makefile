# $NetBSD: Makefile,v 1.17 2019/06/30 20:15:17 nia Exp $
#

DISTNAME=	Mac-Carbon-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mac-Carbon
COMMENT=	Carbon API for perl on Mac OS X

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-powerpc

USE_LANGUAGES=	c c++

PERL5_PACKLIST=	auto/Mac/Carbon/.packlist

BUILDLINK_PASSTHRU_DIRS+=	/Developer/Headers/FlatCarbon

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
