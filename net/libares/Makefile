# $NetBSD: Makefile,v 1.11 2012/10/23 17:18:32 asau Exp $
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

GNU_CONFIGURE=	YES

CFLAGS.Darwin+=		-DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
