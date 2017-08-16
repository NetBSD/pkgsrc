# $NetBSD: Makefile,v 1.14 2017/08/16 20:21:10 wiz Exp $

DISTNAME=	libspf2-1.2.10
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://www.libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFLICTS+=	libspf_alt-[0-9]*

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
