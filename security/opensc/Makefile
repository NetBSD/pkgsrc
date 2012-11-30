# $NetBSD: Makefile,v 1.12 2012/11/30 14:44:34 gdt Exp $

COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

.include "../../security/opensc/Makefile.common"

CONFIGURE_ARGS+=	--with-xsl-stylesheetsdir=${BUILDLINK_PREFIX.docbook-xsl}/share/xsl/docbook

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

# build tools for doc
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/docbook-xsl/buildlink3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
