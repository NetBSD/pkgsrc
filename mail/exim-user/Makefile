# $NetBSD: Makefile,v 1.3 2003/08/02 17:00:07 jmmv Exp $

DISTNAME=	exim-user-4.10
PKGREVISION=	1
CATEGORIES=	mail net
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=	jmc@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Pre-req package for exim to setup user needed for build/use

USE_PKGINSTALL=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	EXIM_GROUP EXIM_USER
PKG_GROUPS=	${EXIM_GROUP}
PKG_USERS=	${EXIM_USER}:${EXIM_GROUP}:8:Exim\\ mail\\ server\\ user:/var/mail:/sbin/nologin

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
