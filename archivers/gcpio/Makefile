# $NetBSD: Makefile,v 1.5 1998/04/18 17:13:05 frueauf Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

MAN1=		gcpio.1
INFO_FILES=	cpio

.include "../../mk/bsd.pkg.mk"
