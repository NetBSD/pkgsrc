# $NetBSD: Makefile,v 1.9 2003/03/06 19:08:10 jlam Exp $
#

DISTNAME=		rdesktop-1.2.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK2=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
ALL_TARGET=		rdesktop

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
