# $NetBSD: Makefile,v 1.32 2023/10/24 22:10:46 wiz Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-gssapi/}
PKGREVISION=	1
COMMENT=	Cyrus SASL GSSAPI authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

BUILD_DIRS=	plugins
BUILD_TARGET=	libgssapiv2.la

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libgssapiv2.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
