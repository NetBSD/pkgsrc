# $NetBSD: Makefile,v 1.13 2014/05/29 23:35:18 wiz Exp $
#

DISTNAME=	msnre-0.91
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msnre/}

MAINTAINER=	luapzz@gmail.com
HOMEPAGE=	http://msnre.sourceforge.net/
COMMENT=	Console-based MSN Instant Messenger clone

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Curses-[0-9]*:../../devel/p5-Curses
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

PERL5_PACKLIST= auto/msnre/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
