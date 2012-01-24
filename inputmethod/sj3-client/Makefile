# $NetBSD: Makefile,v 1.2 2012/01/24 20:39:59 joerg Exp $
#

.include "../../inputmethod/sj3/Makefile.common"

PKGNAME=	${DISTNAME:S/sj3-/sj3-client-/}
PKGREVISION=	1

COMMENT=	SJ3 Japanese input method client & library

CONFLICTS=	sj3-lib-[0-9]* sj3-server-bin-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-client

.include "../../mk/bsd.pkg.mk"
