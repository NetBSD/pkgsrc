# $NetBSD: Makefile,v 1.14 2005/05/13 13:25:55 salo Exp $

DISTNAME=	maradns-1.0.28
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems

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
	@${SED} -e s,@@PKGSYSCONFDIR@@,${PKG_SYSCONFDIR},			\
	    ${WRKSRC}/parse/ParseMaraRc.c > ${WRKSRC}/parse/ParseMaraRc.sed
	@${MV} ${WRKSRC}/parse/ParseMaraRc.sed ${WRKSRC}/parse/ParseMaraRc.c

post-install:
	@${MV} ${PREFIX}/share/doc/maradns/examples \
		${PREFIX}/share/examples/maradns

.include "../../mk/bsd.pkg.mk"
