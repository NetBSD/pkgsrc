# $NetBSD: Makefile,v 1.3 2002/08/25 18:39:32 jlam Exp $

DISTNAME=	hesiod-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	kpneal@pobox.org
COMMENT=	Hesiod network database client and library

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/hesiod.h) && !defined(USE_HESIOD)
IGNORE=		"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
