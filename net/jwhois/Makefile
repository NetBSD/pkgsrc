# $NetBSD: Makefile,v 1.49 2005/01/29 18:10:05 kim Exp $
#

DISTNAME=		jwhois-3.2.2
PKGREVISION=		14
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db

LIBS.SunOS+=		-lnsl -lsocket

INFO_FILES=		jwhois.info

BUILD_DEFS+=		JWHOIS_ENABLE_CACHE

.if defined(JWHOIS_ENABLE_CACHE)
CONFIGURE_ARGS+=	--with-cache
CONF_FILES_PERMS=	/dev/null /${VARBASE}/db/jwhois.db	\
			${ROOT_USER} nogroup 0666
.else
CONFIGURE_ARGS+=	--without-cache
.endif

EGDIR=			${PREFIX}/share/examples/jwhois
CONF_FILES=		${EGDIR}/jwhois.conf.default	\
			${PKG_SYSCONFDIR}/jwhois.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf	\
		${EGDIR}/jwhois.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
