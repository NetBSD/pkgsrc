# $NetBSD: Makefile,v 1.15 2022/04/02 21:41:38 spz Exp $

DISTNAME=	libspf2-1.2.11
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFLICTS+=	libspf_alt-[0-9]*

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
