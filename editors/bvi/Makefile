# $NetBSD: Makefile,v 1.28 2016/06/19 16:55:28 tsutsui Exp $
#

DISTNAME=	bvi-1.4.0.src
PKGNAME=	bvi-1.4.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
