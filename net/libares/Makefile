# $NetBSD: Makefile,v 1.10 2010/08/16 09:48:01 wiz Exp $
#

DISTNAME=	ares-1.1.1
PKGNAME=	libares-1.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Asynchronous DNS resolver library

CONFLICTS+=	libcares-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

CFLAGS.Darwin+=		-DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
