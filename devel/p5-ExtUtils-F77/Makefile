# $NetBSD: Makefile,v 1.37 2019/08/11 13:19:23 wiz Exp $

DISTNAME=	ExtUtils-F77-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-F77
COMMENT=	Perl module for determining how to link Fortran and C
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		fortran77
PERL5_PACKLIST=		auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
