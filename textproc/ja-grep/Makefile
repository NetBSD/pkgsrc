# $NetBSD: Makefile,v 1.3 2005/03/24 21:13:02 wiz Exp $

DISTNAME=	grep-2.0
PKGNAME=	ja-grep-2.0
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep + multi-byte extension

GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-grep
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-grep

.include "../../mk/bsd.pkg.mk"
