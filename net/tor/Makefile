# $NetBSD: Makefile,v 1.5 2005/02/02 16:41:22 jschauma Exp $
#

DISTNAME=		tor-0.0.9.3
CATEGORIES=		net security
MASTER_SITES=		http://tor.eff.org/dist/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://tor.eff.org
COMMENT=		Anonymizing overlay network for TCP

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/tor/torrc

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/or/tor ${PREFIX}/bin/tor
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/torify ${PREFIX}/bin/torify
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/tor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tor
	${INSTALL_DATA} ${WRKSRC}/src/config/torrc.sample		\
		${PREFIX}/share/examples/tor/torrc.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/tor-tsocks.conf		\
		${PREFIX}/share/examples/tor/tor-tsocks.conf
	${INSTALL_MAN} ${WRKSRC}/doc/tor.1 ${PREFIX}/man/man1/tor.1
	${INSTALL_MAN} ${WRKSRC}/contrib/torify.1 ${PREFIX}/man/man1/torify.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
