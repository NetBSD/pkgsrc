# $NetBSD: Makefile,v 1.1.1.1 2004/01/12 17:16:43 xtraeme Exp $
#

.include "${.CURDIR}/../pnetlib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-nox11-/}

CONFIGURE_ARGS+=	--without-x

PLIST_SUBST+=		WITH_X11="@comment "
CONFLICTS=		pnetlib-[0-9]*

.include "../../mk/bsd.pkg.mk"
