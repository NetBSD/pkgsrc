# $NetBSD: Makefile,v 1.6 2006/04/05 22:24:50 jlam Exp $

DISTNAME=	bc-1.06
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

USE_TOOLS+=	flex
GNU_CONFIGURE=	YES
INFO_FILES=	bc.info dc.info

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
