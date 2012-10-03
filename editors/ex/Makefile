# $NetBSD: Makefile,v 1.10 2012/10/03 11:43:33 asau Exp $
#

DISTNAME=	ex-040103
PKGNAME=	ex-20040103
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ex-vi/files/ex-vi/040103/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ex-vi.sourceforge.net/
COMMENT=	Berkeley vi 3.7
LICENSE=	original-bsd

MAKE_DIRS_PERMS+=	${VARBASE}/tmp/vi.recover ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
