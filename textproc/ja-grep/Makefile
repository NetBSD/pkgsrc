# $NetBSD: Makefile,v 1.4 2006/03/11 13:10:42 wiz Exp $

DISTNAME=	grep-2.4.2
PKGNAME=	ja-grep-2.4.2
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

PATCH_SITES=    http://www.hinadori.atnifty.com/~wills/program/
PATCHFILES=     grep-2.4.2-mlb2.patch.gz
PATCH_DIST_STRIP=       -p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep + multi-byte extension

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--program-transform-name='s,^,j,'
TEST_TARGET=	check

INFO_FILES=	grep.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-grep
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-grep

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
