# $NetBSD: Makefile,v 1.33 2018/05/15 18:28:42 jperkin Exp $

DISTNAME=	Compress-Bzip2-2.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Bzip2/
COMMENT=	Perl5 interface to bzip2 compression library
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Compress/Bzip2/.packlist

MAKE_ENV+=	BZLIB_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include
MAKE_ENV+=	BZLIB_LIB=${BUILDLINK_PREFIX.bzip2}/lib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
