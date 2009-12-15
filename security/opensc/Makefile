# $NetBSD: Makefile,v 1.4 2009/12/15 22:10:39 joerg Exp $

COMMENT=		Smart Card drivers and middleware
PKGREVISION=		2
LICENSE=		gnu-lgpl-v2.1

.include "../../security/opensc/Makefile.common"

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-nsplugin

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
