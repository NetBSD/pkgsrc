# $NetBSD: Makefile,v 1.10 2012/10/23 18:16:38 asau Exp $

COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

.include "../../security/opensc/Makefile.common"

PKGREVISION=	3

CONFIGURE_ARGS+=	--disable-nsplugin

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
