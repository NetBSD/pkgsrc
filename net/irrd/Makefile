# $NetBSD: Makefile,v 1.40 2007/12/02 08:32:24 rillig Exp $

DISTNAME=	irrd2.2.8
PKGNAME=	irrd-2.2.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.irrd.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/
COMMENT=	Internet Routing Registry Daemon

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=		automake flex perl:run yacc

WRKSRC=			${WRKDIR}/${DISTNAME}/src

PKG_OPTIONS_VAR=	PKG_OPTIONS.irrd
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-thread

#PTHREAD_AUTO_VARS=	yes
#PTHREAD_OPTS+=		require
#.include "../../mk/pthread.buildlink3.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

REPLACE_PERL+=		programs/irrdcacher/irrdcacher
REPLACE_PERL+=		programs/irrdcacher/ripe2rpsl

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

pre-configure:
	cd ${WRKSRC} && aclocal && autoheader && autoconf

post-install:
	cd ${WRKSRC}/programs/IRRd && ${MAKE} install-man
	cd ${WRKSRC}/programs/irrdcacher && \
	${INSTALL_SCRIPT} irrdcacher ${PREFIX}/sbin && \
	${INSTALL_SCRIPT} ripe2rpsl ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
