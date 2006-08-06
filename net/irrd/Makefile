# $NetBSD: Makefile,v 1.36 2006/08/06 07:09:51 kim Exp $

DISTNAME=	irrd2.2.8
PKGNAME=	irrd-2.2.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.irrd.net/ \
		ftp://ftp.merit.edu/radb/irrd/ \
		ftp://ftp.merit.edu/radb/irrd/old_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/
COMMENT=	Internet Routing Registry Daemon

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=		automake flex perl:run

WRKSRC=			${WRKDIR}/${DISTNAME}/src

#PTHREAD_AUTO_VARS=	yes
#PTHREAD_OPTS+=		require

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-thread

BUILD_DEFS+=		USE_INET6

#CPPFLAGS+=		-I${LOCALBASE}/include

REPLACE_PERL+=		programs/irrdcacher/irrdcacher
REPLACE_PERL+=		programs/irrdcacher/ripe2rpsl

pre-configure:
	cd ${WRKSRC} && aclocal && autoheader && autoconf

post-install:
	cd ${WRKSRC}/programs/IRRd && ${MAKE} install-man
	cd ${WRKSRC}/programs/irrdcacher && \
	${INSTALL_SCRIPT} irrdcacher ${PREFIX}/sbin && \
	${INSTALL_SCRIPT} ripe2rpsl ${PREFIX}/sbin

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
# default
# CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
