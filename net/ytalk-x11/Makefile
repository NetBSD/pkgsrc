# $NetBSD: Makefile,v 1.1.1.1 2004/03/06 12:05:20 grant Exp $

.include "../../net/ytalk/Makefile.common"

PKGNAME=	ytalk-x11-3.1.1
CATEGORIES+=	x11
COMMENT=	Multi-user replacement for UNIX talk (includes X11 support)

CONFIGURE_ARGS+=--with-x
USE_X11=	yes

CONFLICTS+=	ytalk-[0-9]*

DESCR_SRC=	${.CURDIR}/../../net/ytalk/DESCR
DISTINFO_FILE=	${.CURDIR}/../../net/ytalk/distinfo
PATCHDIR=	${.CURDIR}/../../net/ytalk/patches
PLIST_SRC=	${.CURDIR}/../../net/ytalk/PLIST

.include "../../mk/bsd.pkg.mk"
