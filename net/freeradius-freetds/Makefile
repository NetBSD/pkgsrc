# $NetBSD: Makefile,v 1.32 2025/05/06 12:07:33 wiz Exp $

PKGREVISION= 4
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-freetds/}
COMMENT=	Free RADIUS FreeTDS support

CONFIGURE_ARGS+=	--with-rlm_sql_freetds
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
