# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/18 07:54:44 rh Exp $
#
# This Makefile fragment is included by packages that use soup.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(SOUP_BUILDLINK2_MK)
SOUP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			soup
BUILDLINK_DEPENDS.soup?=		soup>=0.7.10
BUILDLINK_PKGSRCDIR.soup?=		../../net/soup

EVAL_PREFIX+=	BUILDLINK_PREFIX.soup=soup
BUILDLINK_PREFIX.soup_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.soup+=	include/soup/libsoup/*.h
BUILDLINK_FILES.soup+=	include/soup/libwsdl/*.h
BUILDLINK_FILES.soup+=	lib/libsoup-apache.*
BUILDLINK_FILES.soup+=	lib/libsoup.*
BUILDLINK_FILES.soup+=	lib/libwsdl.*
BUILDLINK_FILES.soup+=	lib/pkgconfig/soup.pc
BUILDLINK_FILES.soup+=	lib/soupConf.sh
BUILDLINK_FILES.soup+=	lib/soup_apacheConf.sh
BUILDLINK_FILES.soup+=	lib/soup_wsdlConf.sh

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"

BUILDLINK_TARGETS+=	soup-buildlink

soup-buildlink: _BUILDLINK_USE

.endif	# SOUP_BUILDLINK2_MK
