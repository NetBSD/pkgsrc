# $NetBSD: Makefile,v 1.81 2026/11/25 17:16:32 wiz Exp $

DISTNAME=	modsecurity-v2.9.15
PKGNAME=	ap24-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_GITHUB:=owasp-modsecurity/}
GITHUB_PROJECT=	ModSecurity
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/owasp-modsecurity/ModSecurity/
COMMENT=	Intrusion detection and prevention engine for web applications
LICENSE=	apache-2.0

APACHE_MODULE=		yes
USE_LANGUAGES=		c++ c

.include "options.mk"

GNU_CONFIGURE=			YES
USE_TOOLS+=			pax pkg-config
USE_LIBTOOL=			yes
BUILD_DIRS=			apache2

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua51}
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
	${INSTALL_DATA} ${WRKSRC}/doc/README.txt  ${DESTDIR}${PREFIX}/${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/modsecurity.conf-recommended ${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/${DOCDIR}/README.pkgsrc

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../www/apache24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
