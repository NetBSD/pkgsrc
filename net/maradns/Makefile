# $NetBSD: Makefile,v 1.12 2005/03/14 23:41:35 wiz Exp $

DISTNAME=	maradns-1.0.18
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
HAS_CONFIGURE=		yes
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
MAKE_ENV+=		LANGUAGE="en"

EGDIR=		${PREFIX}/share/examples/maradns
CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

.include "../../mk/pthread.buildlink3.mk"
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	${SED} -e s,@@PKGSYSCONFDIR@@,${PKG_SYSCONFDIR},			\
	    ${WRKSRC}/parse/ParseMaraRc.c > ${WRKSRC}/parse/ParseMaraRc.sed
	${MV} ${WRKSRC}/parse/ParseMaraRc.sed ${WRKSRC}/parse/ParseMaraRc.c

post-install:
	${MV} ${PREFIX}/share/doc/maradns/examples \
		${PREFIX}/share/examples/maradns

.include "../../mk/bsd.pkg.mk"
