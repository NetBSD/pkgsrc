# $NetBSD: Makefile,v 1.4 2018/04/17 22:29:45 wiz Exp $

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
