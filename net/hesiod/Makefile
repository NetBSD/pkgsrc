# $NetBSD: Makefile,v 1.5 2002/12/07 02:39:00 schmonz Exp $

DISTNAME=	hesiod-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	kpneal@pobox.org
COMMENT=	Hesiod network database client and library

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/hesiod.h) && !defined(USE_HESIOD)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

pre-build:
	@${MV} ${WRKSRC}/hesinfo.1 ${WRKSRC}/hesinfo.1.orig
	@${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|' \
		${WRKSRC}/hesinfo.1.orig > ${WRKSRC}/hesinfo.1

.include "../../mk/bsd.pkg.mk"
