# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:32 rh Exp $
# FreeBSD Id: Makefile,v 1.14 1998/04/05 04:46:33 max Exp $

DISTNAME=	kakasi-2.3.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://kakasi.namazu.org/

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PKGLIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/ja_JP.EUC/man1
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.cat ${PREFIX}/man/ja_JP.EUC/cat1

.include "../../mk/bsd.pkg.mk"
