# $NetBSD: Makefile,v 1.3 2012/10/06 14:25:18 asau Exp $
#

.include "../../inputmethod/sj3/Makefile.common"

PKGNAME=	${DISTNAME:S/sj3-/sj3-client-/}
PKGREVISION=	1

COMMENT=	SJ3 Japanese input method client & library

CONFLICTS=	sj3-lib-[0-9]* sj3-server-bin-[0-9]*

CONFIGURE_ARGS+=	--enable-client

.include "../../mk/bsd.pkg.mk"
