# $NetBSD: Makefile,v 1.9 1998/06/10 08:02:08 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=	zip-2.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/
DISTFILES=	zip22.tar.gz

MAINTAINER=	packages@netbsd.org

MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}"
ALL_TARGET=	generic
MAN1=		zip.1 zipnote.1 zipcloak.1 zipsplit.1

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	ln -fs zip.1 ${PREFIX}/man/man1/zipcloak.1
	ln -fs zip.1 ${PREFIX}/man/man1/zipnote.1
	ln -fs zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
