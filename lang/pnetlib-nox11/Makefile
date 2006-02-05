# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:47 joerg Exp $
#

.include "${.CURDIR}/../pnetlib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	1

CONFIGURE_ARGS+=	--without-x

PLIST_SUBST+=		WITH_X11="@comment "
CONFLICTS=		pnetlib-[0-9]*

.include "../../mk/bsd.pkg.mk"
