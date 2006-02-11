# $NetBSD: Makefile,v 1.1.1.1 2006/02/11 16:49:04 rillig Exp $

DISTNAME=	kcc
PKGNAME=	kcc-1.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_FREEBSD} \
		ftp://ftp.sra.co.jp/pub/os/linux/JE/sources/base/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	# empty
COMMENT=	Kanji code converter with auto encoding detection

MAKE_FLAGS+=	BINPATH=${PREFIX:Q}/bin
MAKE_FLAGS+=	MANPATH=${PREFIX:Q}/man
MAKE_FLAGS+=	JMANDIR=ja_JP.EUC

INSTALL_TARGET=	install install.man
INSTALLATION_DIRS=	man/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
