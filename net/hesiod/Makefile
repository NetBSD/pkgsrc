# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:46 rillig Exp $

DISTNAME=	hesiod-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	kpneal@pobox.org
COMMENT=	Hesiod network database client and library

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/hesiod.h) && !defined(USE_HESIOD)
PKG_SKIP_REASON+=	"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CFLAGS.Darwin+=		-DBIND_8_COMPAT

pre-build:
	@${MV} ${WRKSRC}/hesinfo.1 ${WRKSRC}/hesinfo.1.orig
	@${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|' \
		${WRKSRC}/hesinfo.1.orig > ${WRKSRC}/hesinfo.1

.include "../../mk/bsd.pkg.mk"
