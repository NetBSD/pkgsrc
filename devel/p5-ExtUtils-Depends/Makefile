# $NetBSD: Makefile,v 1.13 2008/04/21 14:38:09 xtraeme Exp $
#

DISTNAME=	ExtUtils-Depends-0.300
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Easily build XS extensions that depend on XS extensions

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/ExtUtils/Depends/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
