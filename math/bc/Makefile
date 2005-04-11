# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:28 tv Exp $

DISTNAME=	bc-1.06
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

GNU_CONFIGURE=	YES
INFO_FILES=	bc.info dc.info

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/bin/flex)
BUILD_DEPENDS+=	flex-[0-9]*:../../devel/flex
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
