# $NetBSD: Makefile,v 1.6 2003/02/10 02:27:10 grant Exp $
#

DISTNAME=		rdesktop-1.1.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

ALL_TARGET=		rdesktop

USE_X11=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

.include "../../mk/bsd.pkg.mk"
