# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:00 tv Exp $
#

DISTNAME=		tor-0.0.7
PKGREVISION=	1
CATEGORIES=		net security
MASTER_SITES=		http://freehaven.net/tor/dist/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://freehaven.net/tor/dist/
COMMENT=		Anonymizing overlay network for TCP

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONF_FILES=		${PREFIX}/share/examples/tor/dirservers 	\
				${PKG_SYSCONFDIR}/tor/dirservers
CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/tor/torrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/or/tor ${PREFIX}/bin/tor
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/torify ${PREFIX}/bin/torify
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/tor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tor
	${INSTALL_DATA} ${WRKSRC}/src/config/dirservers 		\
		${PREFIX}/share/examples/tor/dirservers
	${INSTALL_DATA} ${WRKSRC}/src/config/torrc.sample		\
		${PREFIX}/share/examples/tor/torrc.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/tor-tsocks.conf		\
		${PREFIX}/share/examples/tor/tor-tsocks.conf
	${INSTALL_MAN} ${WRKSRC}/doc/tor.1 ${PREFIX}/man/man1/tor.1
	${INSTALL_MAN} ${WRKSRC}/contrib/torify.1 ${PREFIX}/man/man1/torify.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
