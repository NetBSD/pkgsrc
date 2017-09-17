# $NetBSD: Makefile,v 1.2 2017/09/17 15:05:32 taca Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-freetds/}
COMMENT=		Free RADIUS FreeTDS support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_freetds

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
