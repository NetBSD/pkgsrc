# $NetBSD: Makefile,v 1.4 2025/05/06 12:07:35 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-unixodbc/}
COMMENT=	Free RADIUS UNIXODBC support

CONFIGURE_ARGS+=	--with-rlm_sql_unixodbc
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_unixodbc.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
