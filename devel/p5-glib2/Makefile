# $NetBSD: Makefile,v 1.6 2004/11/12 00:24:14 seb Exp $
#

DISTNAME=	Glib-${DIST_VERSION}
PKGNAME=	p5-glib2-${DIST_VERSION}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for Glib 2

DEPENDS+=	p5-ExtUtils-Depends>=0.2:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
PERL5_REQD=	5.8
MAKE_PARAMS+=	disable-threadsafe

DIST_VERSION=	1.040

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Glib/.packlist

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
