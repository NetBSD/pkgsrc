# $NetBSD: Makefile,v 1.5 2003/11/14 21:19:03 cube Exp $

DISTNAME=	maradns-1.0.18
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		maradns
HAS_CONFIGURE=		yes
PTHREAD_OPTS+=		require
MAKE_ENV+=		LANGUAGE="en"

EGDIR=		${PREFIX}/share/examples/maradns
CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

post-patch:
	${SED} -e s,@@PKGSYSCONFDIR@@,${PKG_SYSCONFDIR},			\
	    ${WRKSRC}/parse/ParseMaraRc.c > ${WRKSRC}/parse/ParseMaraRc.sed
	${MV} ${WRKSRC}/parse/ParseMaraRc.sed ${WRKSRC}/parse/ParseMaraRc.c

post-install:
	${MV} ${PREFIX}/share/doc/maradns/examples \
		${PREFIX}/share/examples/maradns

.include "../../mk/pthread.buildlink2.mk"
LDFLAGS+=	${PTHREAD_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
