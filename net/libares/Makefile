# $NetBSD: Makefile,v 1.9 2010/07/25 02:35:35 obache Exp $
#

DISTNAME=	ares-1.1.1
PKGNAME=	libares-1.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	sommerfeld@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Asynchronous DNS resolver library

CONFLICTS+=	libcares-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

CFLAGS.Darwin+=		-DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
