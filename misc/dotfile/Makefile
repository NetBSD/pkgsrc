# $NetBSD: Makefile,v 1.23 2005/01/12 21:12:17 minskim Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.4.1
CATEGORIES=	misc tk
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	oly@world.std.com
HOMEPAGE=	http://www.blackie.dk/dotfile/
COMMENT=	GUI dotfile generator program to create .config files

DEPENDS+=	tk>=8.3.2:../../x11/tk

BUILD_DEFS+=	DOTFILE_LANG

# `english' or `japanese'
DOTFILE_LANG?=	english

GNU_CONFIGURE=	yes
NO_BUILD=

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	cd ${WRKSRC}/Doc && ${PAX} -rw . ${PREFIX}/share/doc/${PKGNAME}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/share/doc/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
