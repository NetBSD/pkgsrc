# $NetBSD: Makefile,v 1.3 2005/05/23 09:09:35 rillig Exp $
#

DISTNAME=	msnre-0.91
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msnre/}

MAINTAINER=	luapzz@gmail.com
HOMEPAGE=	http://msnre.sourceforge.net/
COMMENT=	Console-based MSN Instant Messenger clone

DEPENDS+=	p5-Curses-[0-9]*:../../devel/p5-Curses
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/msnre/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
