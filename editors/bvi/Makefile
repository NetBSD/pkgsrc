# $NetBSD: Makefile,v 1.30 2020/02/20 14:31:48 nia Exp $
#

DISTNAME=	bvi-1.4.1.src
PKGNAME=	bvi-1.4.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
