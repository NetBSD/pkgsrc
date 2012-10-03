# $NetBSD: Makefile,v 1.14 2012/10/03 00:20:11 asau Exp $

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

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Program for previewing DVI files (ASCII Japanese TeX)
LICENSE=	no-commercial-use

DEPENDS+=	ja-less>=358:../../misc/ja-less

DIST_SUBDIR=	ja-dvi2tty

MAKE_FLAGS+=	CFLAGS="${CFLAGS} -DDEFPAGER='\"${PREFIX}/bin/jless\"'"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jdvi2tty ${DESTDIR}${PREFIX}/bin/jdvi2tty
	${INSTALL_PROGRAM} ${WRKSRC}/disdvi ${DESTDIR}${PREFIX}/bin/jdisdvi
	${INSTALL_MAN} ${WRKSRC}/dvi2tty.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/jdvi2tty.1

.include "../../mk/bsd.pkg.mk"
