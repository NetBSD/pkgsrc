# $NetBSD: Makefile,v 1.2 1999/07/02 08:37:28 agc Exp $
#

DISTNAME=		ftp-19980903
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

PREFIX=			/usr
WRKSRC=			${WRKDIR}/ftp
MAKE_ENV+=		BINDIR=/usr/bin MANDIR=/usr/share/man
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
