# $NetBSD: Makefile,v 1.9 2011/12/17 10:15:20 sbd Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_DIRS_PERMS+=	${VARBASE}/tmp/vi.recover ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
