# $NetBSD: Makefile,v 1.2 2005/06/01 18:03:08 jlam Exp $

.include "../../net/ytalk/Makefile.common"

PKGNAME=	ytalk-x11-3.1.1
CATEGORIES+=	x11
COMMENT=	Multi-user replacement for UNIX talk (includes X11 support)

CONFIGURE_ARGS+=--with-x

CONFLICTS+=	ytalk-[0-9]*

DESCR_SRC=	${.CURDIR}/../../net/ytalk/DESCR
DISTINFO_FILE=	${.CURDIR}/../../net/ytalk/distinfo
PATCHDIR=	${.CURDIR}/../../net/ytalk/patches
PLIST_SRC=	${.CURDIR}/../../net/ytalk/PLIST

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
