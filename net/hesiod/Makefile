# $NetBSD: Makefile,v 1.13 2012/05/13 09:02:55 sbd Exp $

DISTNAME=	hesiod-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	kpneal@pobox.org
COMMENT=	Hesiod network database client and library

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CFLAGS.Darwin+=		-DBIND_8_COMPAT
LDFLAGS.Linux+=		-lresolv

pre-build:
	@${MV} ${WRKSRC}/hesinfo.1 ${WRKSRC}/hesinfo.1.orig
	@${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|' \
		${WRKSRC}/hesinfo.1.orig > ${WRKSRC}/hesinfo.1

.include "../../mk/bsd.pkg.mk"
