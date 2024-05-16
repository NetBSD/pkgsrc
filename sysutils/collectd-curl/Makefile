# $NetBSD: Makefile,v 1.41 2024/05/16 06:15:32 wiz Exp $

COLLECTD_PACKAGE=	curl
COLLECTD_PLUGINS=	curl curl_json curl_xml apache bind nginx write_http ascent

COMMENT=		Statistics collection daemon - curl-based plugins
PKGREVISION=		11

.include "../../devel/yajl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

COLLECTD_LIB.curl=	${BUILDLINK_PREFIX.curl}
COLLECTD_LIB.yajl=	${BUILDLINK_PREFIX.yajl}
COLLECTD_LIB.xml2=	${BUILDLINK_PREFIX.libxml2}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
