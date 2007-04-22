# $NetBSD: Makefile,v 1.3 2007/04/22 09:13:41 heinz Exp $

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
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/libintl-perl/.packlist

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
