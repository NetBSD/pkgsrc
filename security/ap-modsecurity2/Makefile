# $NetBSD: Makefile,v 1.12 2009/02/23 22:01:11 adrianp Exp $

DISTNAME=	modsecurity-apache_2.5.7
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/apache_//}
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--with-apr=${PREFIX}
CONFIGURE_ARGS+=	--with-apu=${PREFIX}
CONFIGURE_ARGS+=        --with-libxml=${PREFIX}

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
