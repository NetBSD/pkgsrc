# $NetBSD: Makefile,v 1.3 2006/03/14 01:42:55 joerg Exp $

DISTNAME=		nc6-1.0
PKGNAME=		${DISTNAME:S/nc/netcat/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.deepspace6.net/pub/ds6/sources/nc6/
MASTER_SITES+=		http://ftp.deepspace6.net/pub/ds6/sources/nc6/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ghen@NetBSD.org
COMMENT=		Network swiss army knife
HOMEPAGE=		http://www.deepspace6.net/projects/netcat6.html

GNU_CONFIGURE=		yes

# don't auto-detect IPv6, use options.mk:
CONFIGURE_ARGS+=	--disable-stack-guess

USE_PKGLOCALEDIR=	yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
