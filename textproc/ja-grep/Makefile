# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:00:42 seb Exp $
# FreeBSD Id: Makefile,v 1.10 1999/01/27 07:41:16 fenner Exp $

DISTNAME=	grep-2.0
PKGNAME=	ja-grep-2.0
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep + multi-byte extension

GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ja-grep
	${INSTALL_DATA} ${WRKSRC}/README.MB ${PREFIX}/share/doc/ja-grep

.include "../../mk/bsd.pkg.mk"
