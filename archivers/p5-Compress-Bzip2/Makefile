# $NetBSD: Makefile,v 1.40 2022/06/28 11:30:53 wiz Exp $

DISTNAME=	Compress-Bzip2-2.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Compress-Bzip2
COMMENT=	Perl5 interface to bzip2 compression library
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

MAKE_ENV+=	BZLIB_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include
MAKE_ENV+=	BZLIB_LIB=${BUILDLINK_PREFIX.bzip2}/lib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
