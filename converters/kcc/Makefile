# $NetBSD: Makefile,v 1.4 2008/01/21 03:04:30 obache Exp $

DISTNAME=	kcc
PKGNAME=	kcc-1.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_FREEBSD} \
		ftp://ftp.sra.co.jp/pub/os/linux/JE/sources/base/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Kanji code converter with auto encoding detection

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	BINPATH=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MANPATH=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	JMANDIR=ja_JP.EUC

INSTALL_TARGET=	install install.man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
