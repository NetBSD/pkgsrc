# $NetBSD: Makefile,v 1.2 2001/09/30 11:15:19 rh Exp $
#

DISTNAME=		rdesktop-1.1.0
CATEGORIES=		net
MASTER_SITES=		http://prdownloads.sourceforge.net/rdesktop/

MAINTAINER=		grant@grunta.com
HOMEPAGE=		http://rdesktop.sourceforge.net/
COMMENT=		Open-source Remote Desktop Protocol client

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

ALL_TARGET=		rdesktop

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
