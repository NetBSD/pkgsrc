# $NetBSD: Makefile,v 1.23 2004/08/01 20:00:29 jlam Exp $

DISTNAME=       lha-114i
PKGNAME=	lha-114.9
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www2m.biglobe.ne.jp/~dolphin/lha/lha-unix.htm
COMMENT=	Archive files using LZW compression (.lzh files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

MAKE_FLAGS=	MAKE="${MAKE_PROGRAM}"

.include "../../mk/bsd.prefs.mk"

LHA_CPPFLAGS=	-DSYSTIME_HAS_NO_TM -DMKTIME -DUSESTRCASECMP -DSYSV_SYSTEM_DIR
.if ${OPSYS} == "Darwin"
LHA_CPPFLAGS+=	-DHAVE_NO_LCHOWN
.endif
MAKE_FLAGS+=	MACHINE="${LHA_CPPFLAGS}"

INSTALLATION_DIRS=	bin man/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
