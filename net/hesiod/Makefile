# $NetBSD: Makefile,v 1.1.1.1 2001/11/29 11:41:28 seb Exp $

DISTNAME=	hesiod-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	kpneal@pobox.org
COMMENT=	Hesiod network database client and library

GNU_CONFIGURE=	YES

.if exists(/usr/include/hesiod.h) && !defined(NEED_HESIOD)
IGNORE=		"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
