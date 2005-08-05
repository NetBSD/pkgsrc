# $NetBSD: Makefile,v 1.1.1.1 2005/08/05 22:00:49 reinoud Exp $
#

DISTNAME=		libbt-1.04
PKGNAME=		${DISTNAME:S/libbt/btget/}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libbt/}

MAINTAINER=		reinoud@NetBSD.org
HOMEPAGE=		http://libbt.sourceforge.net/
COMMENT=		Fast bittorrent client and library written in C

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/btget ${PREFIX}/bin/btget
	${INSTALL_PROGRAM} ${WRKSRC}/src/btlist ${PREFIX}/bin/btlist
	${INSTALL_PROGRAM} ${WRKSRC}/src/btcheck ${PREFIX}/bin/btcheck
	${INSTALL_MAN} ${WRKSRC}/man/btget.1 ${PREFIX}/man/man1/btget.1
	${INSTALL_MAN} ${WRKSRC}/man/btlist.1 ${PREFIX}/man/man1/btlist.1
	${INSTALL_MAN} ${WRKSRC}/man/btcheck.1 ${PREFIX}/man/man1/btcheck.1

.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
