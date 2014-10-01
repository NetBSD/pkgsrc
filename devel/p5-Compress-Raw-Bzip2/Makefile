# $NetBSD: Makefile,v 1.26 2014/10/01 10:49:53 wiz Exp $

DISTNAME=	Compress-Raw-Bzip2-2.066
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-Raw-Bzip2/
COMMENT=	Perl5 low-level interface to bzip2 compression library
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Compress/Raw/Bzip2/.packlist
MAKE_ENV+=		BUILD_BZIP2=0
MAKE_ENV+=		BZIP2_LIB=${BUILDLINK_PREFIX.bzip2}/lib
MAKE_ENV+=		BZIP2_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
