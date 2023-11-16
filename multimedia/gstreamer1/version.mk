# $NetBSD: version.mk,v 1.7 2023/11/16 09:22:51 wiz Exp $

GST_VERSION=	1.22.6
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
