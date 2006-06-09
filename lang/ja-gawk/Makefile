# $NetBSD: Makefile,v 1.9 2006/06/09 16:14:17 minskim Exp $

DISTNAME=	gawk-3.0.6
PKGNAME=	ja-gawk-3.0.6
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

PATCH_SITES=	http://www.hinadori.atnifty.com/~wills/program/
PATCHFILES=	gawkmb115.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk + multi-byte extension

CONFLICTS=	gawk-[0-9]*

INFO_FILES=	# PLIST

GNU_CONFIGURE=	yes
USE_TOOLS+=	yacc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-gawk
	${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja-gawk
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-gawk

.include "../../mk/bsd.pkg.mk"
