# $NetBSD: Makefile,v 1.55 2005/10/03 21:18:55 agc Exp $
#

DISTNAME=		jwhois-3.2.2
PKGREVISION=		18
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db

LIBS.SunOS+=		-lnsl -lsocket

INFO_FILES=		jwhois.info

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/jwhois
CONF_FILES=		${EGDIR}/jwhois.conf.default	\
			${PKG_SYSCONFDIR}/jwhois.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf	\
		${EGDIR}/jwhois.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
