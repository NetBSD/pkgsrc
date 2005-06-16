# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:43 jlam Exp $

DISTNAME=	dvi2tty5.0
PKGNAME=	ja-dvi2tty-5.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/

PATCH_SITES=	${MASTER_SITE_LOCAL}
#PATCH_SITES=	ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
PATCHFILES=	dvi2tty-ascii-jtex-patch \
		dvi2tty.c-patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Program for previewing DVI files (ASCII Japanese TeX)

DEPENDS=	ja-less>=358:../../misc/ja-less

DIST_SUBDIR=	ja-dvi2tty

LICENSE=	no-commercial-use

MAKE_FLAGS+=	CFLAGS="${CFLAGS} -DDEFPAGER='\"${PREFIX}/bin/jless\"'"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jdvi2tty ${PREFIX}/bin/jdvi2tty
	${INSTALL_PROGRAM} ${WRKSRC}/disdvi ${PREFIX}/bin/jdisdvi
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1/jdvi2tty.1

.include "../../mk/bsd.pkg.mk"
