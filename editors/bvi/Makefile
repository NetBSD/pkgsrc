# $NetBSD: Makefile,v 1.21 2005/12/05 20:50:09 rillig Exp $
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
MAKE_ENV+=	SHELL=${SH:Q}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
