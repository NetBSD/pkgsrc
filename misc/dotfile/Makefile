# $NetBSD: Makefile,v 1.16 2001/02/17 18:08:58 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.4.1
CATEGORIES=	misc tk
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com
HOMEPAGE=	http://www.imada.ou.dk/~blackie/dotfile/
COMMENT=	GUI dotfile generator program to create .config files

DEPENDS+=	tk-8.3.2:../../x11/tk

BUILD_DEFS+=	DOTFILE_LANG

# `english' or `japanese'
DOTFILE_LANG?=	english

GNU_CONFIGURE=	yes
NO_BUILD=

post-install:
	${MKDIR} ${PREFIX}/share/doc/${PKGNAME}
	cd ${WRKSRC}/Doc && ${GTAR} cf - . | ( cd ${PREFIX}/share/doc/${PKGNAME} && ${GTAR} xf - )
	${CHOWN} -R root:${ROOT_GROUP} ${PREFIX}/share/doc/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
