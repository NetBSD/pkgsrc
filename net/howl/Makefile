# $NetBSD: Makefile,v 1.19 2017/08/16 20:45:42 wiz Exp $

DISTNAME=		howl-1.0.0
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
#HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

RCD_SCRIPTS=		howl
PKG_GROUPS+=		${HOWL_GROUP}
PKG_USERS+=		${HOWL_USER:Q}:${HOWL_GROUP:Q}
PKG_GECOS.${HOWL_USER}=	Zeroconf user

PKG_GROUPS_VARS+=	HOWL_GROUP
PKG_USERS_VARS+=	HOWL_USER

FILES_SUBST+=		HOWL_GROUP=${HOWL_GROUP:Q}
FILES_SUBST+=		HOWL_USER=${HOWL_USER:Q}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
