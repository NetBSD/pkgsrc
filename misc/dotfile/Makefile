# $NetBSD: Makefile,v 1.27 2006/02/14 01:01:17 rillig Exp $

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/${PKGNAME_NOREV:Q}
	cd ${WRKSRC:Q}/Doc && ${PAX} -rw . ${PREFIX:Q}/share/doc/${PKGNAME_NOREV:Q}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${PREFIX:Q}/share/doc/${PKGNAME_NOREV:Q}

.include "../../mk/bsd.pkg.mk"
