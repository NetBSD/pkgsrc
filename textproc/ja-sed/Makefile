# $NetBSD: Makefile,v 1.6 2005/03/24 21:13:02 wiz Exp $

DISTNAME=	sed-3.02
PKGNAME=	ja-sed-3.02
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

PATCH_SITES=	http://member.nifty.ne.jp/wills/program/
PATCHFILES=	sedmb108.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU sed + multi-byte extension

INFO_FILES=	sed.info

CONFLICTS+=	gsed-[0-9]*

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-transform-name='s,^,j,'

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-sed
	@${INSTALL_DATA} ${WRKSRC}/OREADME.MB ${PREFIX}/share/doc/ja-sed
	@${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-sed

.include "../../mk/bsd.pkg.mk"
