# $NetBSD: version.mk,v 1.8 2023/11/16 09:31:35 wiz Exp $

GST_VERSION=	1.22.7
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
