# $NetBSD: Makefile,v 1.3 2004/02/21 07:19:12 snj Exp $
# FreeBSD Id: Makefile,v 1.2 1999/05/01 04:00:25 taoka Exp $

DISTNAME=	jhd-2.3
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.iamas.ac.jp/pub1/UNIX/File/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Japanese Hexadecimal Dump

BUILD_DEPENDS=	nkf-1.7:../../converters/nkf

post-build:
	@(cd ${WRKSRC}; ${MV} jhd.1 jhd.1.org; nkf -e jhd.1.org > jhd.1)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhd.1 ${PREFIX}/man/ja_JP.EUC/man1

.include "../../mk/bsd.pkg.mk"
