# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 18:14:04 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-gssapi/}
COMMENT=	Cyrus SASL GSSAPI authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libgssapiv2.la

.include "../../mk/krb5.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libgssapiv2.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
