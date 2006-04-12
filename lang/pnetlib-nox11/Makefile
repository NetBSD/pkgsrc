# $NetBSD: Makefile,v 1.3 2006/04/12 20:50:56 joerg Exp $
#

.include "${.CURDIR}/../pnetlib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	2

CONFIGURE_ARGS+=	--without-x

CONFLICTS=		pnetlib-[0-9]*

.include "../../mk/bsd.pkg.mk"
