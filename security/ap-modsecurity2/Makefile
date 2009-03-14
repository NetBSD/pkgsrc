# $NetBSD: Makefile,v 1.13 2009/03/14 13:45:38 adrianp Exp $

DISTNAME=	modsecurity-apache_2.5.9
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/apache_//}
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../mk/apache.mk"
.include "options.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		pax
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/apache2
USE_LANGUAGES+=		c++ c

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs
CONFIGURE_ARGS+=	--with-pcre=${PREFIX}
CONFIGURE_ARGS+=        --with-libxml=${PREFIX}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	configure
SUBST_SED.config=       -e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_MESSAGE.config=   Fixing configuration files.

EGDIR=			${PREFIX}/share/examples/ap-modsecurity
CONF_FILES=		${EGDIR}/modsecurity.conf-minimal \
			${PKG_SYSCONFDIR}/httpd/modsecurity.conf

BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.59nb2

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ap-modsecurity

	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/modsecurity.conf-minimal ${EGDIR}
	cd ${WRKDIR}/${DISTNAME}/doc && \
		pax -rw . ${PREFIX}/share/doc/ap-modsecurity

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
