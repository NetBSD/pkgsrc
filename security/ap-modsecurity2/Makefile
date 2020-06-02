# $NetBSD: Makefile,v 1.52 2020/06/02 08:24:39 adam Exp $

DISTNAME=	modsecurity-apache_2.7.7
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/apache_//}
PKGREVISION=	22
CATEGORIES=	www security
MASTER_SITES=	https://www.modsecurity.org/tarball/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications
LICENSE=	apache-2.0

APACHE_MODULE=		yes
USE_APR=		yes
USE_LANGUAGES=		c++ c

.include "../../mk/apache.mk"
.include "options.mk"

GNU_CONFIGURE=			YES
USE_TOOLS+=			pax
USE_LIBTOOL=			yes
BUILD_DIRS=			apache2
LUA_VERSIONS_INCOMPATIBLE=	52

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+=	--with-apu=${BUILDLINK_PREFIX.apr-util}

INSTALLATION_DIRS+=	lib/httpd

EGDIR=			share/examples/ap-modsecurity
DOCDIR=			share/doc/ap-modsecurity
INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/modsecurity.conf-recommended \
			${PKG_SYSCONFDIR}/httpd/modsecurity.conf

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/mod_security2.so
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended \
			${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC}/doc && \
		pax -rw . ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
