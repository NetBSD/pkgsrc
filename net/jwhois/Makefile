# $NetBSD: Makefile,v 1.68 2020/04/12 23:59:42 joerg Exp $
#

DISTNAME=		jwhois-4.0
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client
LICENSE=		gnu-gpl-v3

BUILD_DEFS+=		VARBASE

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

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-install
SUBST_FILES.paths=	example/jwhois.conf
SUBST_VARS.paths=	PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf	\
	    ${DESTDIR}${EGDIR}/jwhois.conf.default

.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
