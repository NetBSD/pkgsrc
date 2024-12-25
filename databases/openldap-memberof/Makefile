# $NetBSD: Makefile,v 1.1 2024/12/25 09:40:30 bouyer Exp $

PKGNAME=	${DISTNAME:S/-/-memberof-/}
COMMENT=	memberOf overlay for OpenLDAP

CONFIGURE_ARGS+=	--enable-memberof=mod
MAKE_JOBS_SAFE= 	NO

DEPENDS+=	openldap-server>=2.4.13nb1:../../databases/openldap-server

BUILD_DIRS=		include libraries servers/slapd/overlays
INSTALLATION_DIRS+=	lib/openldap 

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB}			\
		   ${WRKSRC}/servers/slapd/overlays/memberof.la	\
		   ${DESTDIR}${PREFIX}/lib/openldap

.include "../../mk/bsd.prefs.mk"

.include "../../databases/openldap-server/options.mk"

LIBS+=		-L${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	EXTRA_LIBS=${LIBS:M*:Q}

.include "../../databases/openldap/Makefile.common"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
