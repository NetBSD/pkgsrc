# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:00:45 seb Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	gawk-3.0.4
PKGNAME=	ja-gawk-3.0.4
CATEGORIES=	japanese lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	gawkmb112.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk + multi-byte extension

INFO_FILES=	gawk.info

GNU_CONFIGURE=	yes

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-gawk
	@${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja-gawk
	@${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-gawk

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
