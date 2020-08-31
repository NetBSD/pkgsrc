# $NetBSD: Makefile,v 1.19 2020/08/31 18:08:19 wiz Exp $
#

DISTNAME=	Mac-Carbon-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
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
