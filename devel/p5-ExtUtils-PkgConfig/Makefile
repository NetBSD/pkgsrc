# $NetBSD: Makefile,v 1.1.1.1 2004/04/19 17:23:15 xtraeme Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config

PERL5_REQD=	5.8
USE_BUILDLINK3=	yes

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/PkgConfig/.packlist

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
