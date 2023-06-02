# $NetBSD: version.mk,v 1.5 2023/06/02 16:09:47 wiz Exp $

GST_VERSION=	1.22.3
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
