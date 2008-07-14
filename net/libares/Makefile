# $NetBSD: Makefile,v 1.8 2008/07/14 12:56:10 joerg Exp $
#

DISTNAME=	ares-1.1.1
PKGNAME=	libares-1.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	sommerfeld@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Asynchronous DNS resolver library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

CFLAGS.Darwin+=		-DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
