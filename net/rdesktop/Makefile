# $NetBSD: Makefile,v 1.5 2002/07/25 02:48:47 grant Exp $
#

DISTNAME=		rdesktop-1.1.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

ALL_TARGET=		rdesktop

USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

.include "../../mk/bsd.pkg.mk"
