# $NetBSD: Makefile,v 1.1 1998/09/03 11:43:59 agc Exp $
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

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=		yes
.endif

.include "../../mk/bsd.pkg.mk"
