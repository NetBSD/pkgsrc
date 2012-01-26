# $NetBSD: Makefile,v 1.15 2012/01/26 20:19:08 rhaen Exp $
#

DISTNAME=	Set-IntSpan-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sis
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-IntSpan/
COMMENT=	Perl5 module for managing sets of integers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Set/IntSpan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
