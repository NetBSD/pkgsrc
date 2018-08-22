# $NetBSD: Makefile,v 1.47 2018/08/22 09:43:46 wiz Exp $

DISTNAME=	Compress-Raw-Zlib-2.081
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Raw-Zlib/
COMMENT=	Perl5 module interface to the zlib compression library
LICENSE=	${PERL5_LICENSE}

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Compress/Raw/Zlib/.packlist
MAKE_ENV+=		BUILD_ZLIB=False
MAKE_ENV+=		OLD_ZLIB=False
MAKE_ENV+=		ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=		ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
