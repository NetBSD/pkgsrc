# $NetBSD: Makefile,v 1.6 2005/03/24 21:12:55 wiz Exp $

DISTNAME=	gawk-3.0.4
PKGNAME=	ja-gawk-3.0.4
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	gawkmb112.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk + multi-byte extension

CONFLICTS=	gawk-[0-9]*

INFO_FILES=	gawk.info

GNU_CONFIGURE=	yes

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-gawk
	@${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja-gawk
	@${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-gawk

.include "../../mk/bsd.pkg.mk"
