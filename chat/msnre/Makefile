# $NetBSD: Makefile,v 1.1.1.1 2004/12/03 17:30:06 minskim Exp $
#

DISTNAME=	msnre-0.91
CATEGORIES=	chat
MASTER_SITES=	http://puzzle.dl.sourceforge.net/sourceforge/msnre/

MAINTAINER=	luapzz@gmail.com
HOMEPAGE=	http://msnre.sourceforge.net/
COMMENT=	Console-based MSN Instant Messenger clone

DEPENDS+=	p5-Curses-[0-9]*:../../devel/p5-Curses
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/msnre/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
