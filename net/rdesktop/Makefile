# $NetBSD: Makefile,v 1.3 2001/10/02 10:22:21 rh Exp $
#

DISTNAME=		rdesktop-1.1.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@grunta.com
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

ALL_TARGET=		rdesktop

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
