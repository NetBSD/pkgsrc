# $NetBSD: Makefile,v 1.23 2012/10/03 21:54:58 wiz Exp $

DISTNAME=	ExtUtils-F77-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-F77/
COMMENT=	Perl module for determining how to link Fortran and C
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		fortran77
PERL5_PACKLIST=		auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
