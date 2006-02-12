# $NetBSD: Makefile,v 1.14 2006/02/12 05:26:39 rillig Exp $

DISTNAME=		howl-1.0.0
CATEGORIES=		net
MASTER_SITES=		http://www.porchdogsoft.com/download/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.porchdogsoft.com/products/howl/
COMMENT=		Zeroconf (Rendezvous) implementation

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

RCD_SCRIPTS=		howl
PKG_GROUPS+=		${HOWL_GROUP}
PKG_USERS+=		${HOWL_USER:Q}:${HOWL_GROUP:Q}::Zeroconf\ user

BUILD_DEFS+=		HOWL_GROUP HOWL_USER

FILES_SUBST+=		HOWL_GROUP=${HOWL_GROUP:Q}
FILES_SUBST+=		HOWL_USER=${HOWL_USER:Q}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
