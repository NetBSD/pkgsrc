# $NetBSD: Makefile,v 1.9 2001/10/24 07:05:37 cjs Exp $
#

DISTNAME=	bvi-1.3.0.src
PKGNAME=	bvi-1.3.0
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	editors
MASTER_SITES=	http://prdownloads.sourceforge.net/bvi/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
MAKE_ENV+=		SHELL=${SH}

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
