# $NetBSD: Makefile,v 1.31 2020/03/20 11:57:33 nia Exp $
#

DISTNAME=	bvi-1.4.1.src
PKGNAME=	bvi-1.4.1
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
