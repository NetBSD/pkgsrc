# $NetBSD: Makefile,v 1.10 2010/02/20 08:14:44 obache Exp $

DISTNAME=	gawk-3.0.6
PKGNAME=	ja-${DISTNAME}
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

PATCH_SITES=	http://www.hinadori.atnifty.com/~wills/program/
PATCHFILES=	gawkmb115.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk + multi-byte extension
LICENSE=	gnu-gpl-v2

CONFLICTS=	gawk-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

INFO_FILES=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	yacc

INSTALLATION_DIRS+=	share/doc/ja-gawk

post-install:
	${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${DESTDIR}${PREFIX}/share/doc/ja-gawk
	${INSTALL_DATA} ${WRKSRC}/README.MB ${DESTDIR}${PREFIX}/share/doc/ja-gawk

.include "../../mk/bsd.pkg.mk"
