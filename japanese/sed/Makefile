# $NetBSD: Makefile,v 1.2 1999/06/08 09:44:46 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.7 1999/01/27 07:41:18 fenner Exp $

DISTNAME=	sed-3.02
PKGNAME=	ja-sed-3.02
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	sedmb107.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html

INFO_FILES=	sed.info

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-transform-name='s,^,j,'

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-sed
	@${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja-sed
	@${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-sed

.include "../../mk/bsd.pkg.mk"
