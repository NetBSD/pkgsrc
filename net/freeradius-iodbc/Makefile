# $NetBSD: Makefile,v 1.4 2025/05/06 12:07:33 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-iodbc/}
COMMENT=	Free RADIUS iODBC support

CONFIGURE_ARGS+=	--with-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_iodbc.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/iodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
