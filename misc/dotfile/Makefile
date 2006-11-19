# $NetBSD: Makefile,v 1.28 2006/11/19 22:48:07 rillig Exp $

DISTNAME=	dotfile-2.4.1
PKGREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	oly@world.std.com
HOMEPAGE=	http://www.blackie.dk/dotfile/
COMMENT=	GUI dotfile generator program to create .config files

DEPENDS+=	tk>=8.3.2:../../x11/tk

BUILD_DEFS+=	DOTFILE_LANG

.include "../../mk/bsd.prefs.mk"

# `english' or `japanese'
DOTFILE_LANG?=	english

GNU_CONFIGURE=	yes
NO_BUILD=	yes
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}/man1

post-build:
	rm -f ${WRKSRC}/Generator/makeHelp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}
	cd ${WRKSRC:Q}/Doc && ${PAX} -rw -s ',.*\.orig$$,,' . ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
