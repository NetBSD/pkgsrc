# $NetBSD: Makefile,v 1.6 2004/12/27 22:00:31 xtraeme Exp $
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
USE_BUILDLINK3=	yes

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/PkgConfig/.packlist

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
