# $NetBSD: Makefile,v 1.14 2012/12/16 01:52:27 obache Exp $
#

DISTNAME=		libbt-1.05
PKGNAME=		${DISTNAME:S/libbt/btget/}
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libbt/}

MAINTAINER=		reinoud@NetBSD.org
HOMEPAGE=		http://libbt.sourceforge.net/
COMMENT=		Fast bittorrent client and library written in C

USE_TOOLS+=		makedepend
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/btget ${DESTDIR}${PREFIX}/bin/btget
	${INSTALL_PROGRAM} ${WRKSRC}/src/btlist ${DESTDIR}${PREFIX}/bin/btlist
	${INSTALL_PROGRAM} ${WRKSRC}/src/btcheck ${DESTDIR}${PREFIX}/bin/btcheck
	${INSTALL_MAN} ${WRKSRC}/man/btget.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/btget.1
	${INSTALL_MAN} ${WRKSRC}/man/btlist.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/btlist.1
	${INSTALL_MAN} ${WRKSRC}/man/btcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/btcheck.1

.include "../../devel/libuuid/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
