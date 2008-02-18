# $NetBSD: Makefile,v 1.4 2008/02/18 16:39:43 xtraeme Exp $
#

.include "${.CURDIR}/../pnetlib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-nox11-/}
#PKGREVISION=	2

CONFIGURE_ARGS+=	--without-x

CONFLICTS=		pnetlib-[0-9]*

.include "../../mk/bsd.pkg.mk"
