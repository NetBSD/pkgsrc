# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:25 jlam Exp $
#

DISTNAME=	ExtUtils-Depends-0.204
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Easily build XS extensions that depend on XS extensions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD=	5.8

PERL5_PACKLIST=	auto/ExtUtils/Depends/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
