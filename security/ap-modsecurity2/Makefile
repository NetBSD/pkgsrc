# $NetBSD: Makefile,v 1.23 2012/12/16 01:52:31 obache Exp $

DISTNAME=	modsecurity-apache_2.5.13
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/apache_//}
PKGREVISION=	4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

APACHE_MODULE=		yes
PKG_APACHE_ACCEPTED=	apache22
USE_APR=		yes
USE_LANGUAGES=		c++ c

.include "../../mk/apache.mk"
.include "options.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		pax
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/apache2

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+=	--with-apu=${BUILDLINK_PREFIX.apr-util}

INSTALLATION_DIRS+=	lib/httpd
INSTALL_ENV+=		APACHEPREFIX=${BUILDLINK_PREFIX.apache}
INSTALL_ENV+=		DESTDIR=${DESTDIR}

EGDIR=			share/examples/ap-modsecurity
DOCDIR=			share/doc/ap-modsecurity
INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/modsecurity.conf-minimal \
			${PKG_SYSCONFDIR}/httpd/modsecurity.conf

BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.59nb2

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/modsecurity.conf-minimal \
			${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKDIR}/${DISTNAME}/doc && \
		pax -rw . ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
