# $NetBSD: Makefile,v 1.2 2004/04/19 17:41:51 minskim Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD=	5.8
USE_BUILDLINK3=	yes

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/PkgConfig/.packlist

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
