# $NetBSD: Makefile,v 1.65 2012/10/23 17:18:30 asau Exp $
#

DISTNAME=		jwhois-4.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client
LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db

LIBS.SunOS+=		-lnsl -lsocket

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/jwhois
CONF_FILES=		${EGDIR}/jwhois.conf.default	\
			${PKG_SYSCONFDIR}/jwhois.conf
INFO_FILES=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf	\
	    ${DESTDIR}${EGDIR}/jwhois.conf.default

.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
