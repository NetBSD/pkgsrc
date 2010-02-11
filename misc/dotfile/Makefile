# $NetBSD: Makefile,v 1.34 2010/02/11 19:14:19 joerg Exp $

DISTNAME=	dotfile-2.4.1
PKGREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blackie.dk/dotfile/
COMMENT=	GUI dotfile generator program to create .config files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_TOOLS+=	pax

BUILD_DEFS+=	DOTFILE_LANG

.include "../../mk/bsd.prefs.mk"

# `english' or `japanese'
DOTFILE_LANG?=	english

GNU_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/doc/${PKGNAME_NOREV}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \
			prefix=${DESTDIR}${PREFIX}

CHECK_INTERPRETER_SKIP=	share/${DISTNAME}/*

pre-install:
	rm -f ${WRKSRC}/Generator/makeHelp.orig

post-install:
	cd ${WRKSRC:Q}/Doc && pax -rw . ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
