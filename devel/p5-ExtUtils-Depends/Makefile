# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:20 jlam Exp $
#

DISTNAME=	ExtUtils-Depends-0.204
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Easily build XS extensions that depend on XS extensions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/ExtUtils/Depends/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
