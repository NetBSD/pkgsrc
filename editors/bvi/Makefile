# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:40 tv Exp $
#

DISTNAME=	bvi-1.3.2.src
PKGNAME=	bvi-1.3.2
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
