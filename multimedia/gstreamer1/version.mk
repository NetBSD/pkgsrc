# $NetBSD: version.mk,v 1.9 2023/12/31 22:03:01 wiz Exp $

GST_VERSION=	1.22.8
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
