# $NetBSD: Makefile,v 1.3 1999/09/12 23:05:47 bad Exp $
#

DISTNAME=		ftp-19980903
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

LOCALBASE=		/usr
WRKSRC=			${WRKDIR}/ftp
MAKE_ENV+=		BINDIR=/usr/bin MANDIR=/usr/share/man
NO_CONFIGURE=		yes
NO_MTREE=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
