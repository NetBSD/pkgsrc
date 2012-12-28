# $NetBSD: Makefile,v 1.11 2012/12/28 03:03:08 dholland Exp $
#

DISTNAME=	ex-040103
PKGNAME=	ex-20040103
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ex-vi/files/ex-vi/040103/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ex-vi.sourceforge.net/
COMMENT=	Berkeley vi 3.7
LICENSE=	original-bsd

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	post-extract
SUBST_MESSAGE.getline=	Changing 'getline' to 'get_line'
SUBST_FILES.getline=	ex*.c ex_proto.h
SUBST_SED.getline=	-e "s,getline,get_line,g"

MAKE_DIRS_PERMS+=	${VARBASE}/tmp/vi.recover ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
