# $NetBSD: Makefile,v 1.19 2019/08/22 12:23:45 ryoon Exp $

COLLECTD_PACKAGE=	curl
COLLECTD_PLUGINS=	curl curl_json curl_xml apache bind nginx write_http

COMMENT=		Statistics collection daemon - curl-based plugins
PKGREVISION=		9

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-libyajl=${BUILDLINK_PREFIX.yajl}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}

.include "../../devel/yajl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
