# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:25 jlam Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD=	5.8

PERL5_PACKLIST=	auto/ExtUtils/PkgConfig/.packlist

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
