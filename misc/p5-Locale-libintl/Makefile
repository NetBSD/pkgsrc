# $NetBSD: Makefile,v 1.1.1.1 2006/02/17 20:58:38 adrianp Exp $

P5_LIBINTL_VER=	1.16
DISTNAME=	libintl-perl-${P5_LIBINTL_VER}
PKGNAME=	p5-Locale-libintl-${P5_LIBINTL_VER}
CATEGORIES=	misc perl5

CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://search.cpan.org/dist/libintl-perl/
COMMENT=	Perl internationalization library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/libintl-perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
