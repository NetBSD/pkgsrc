# $NetBSD: version.mk,v 1.6 2023/06/29 09:20:44 wiz Exp $

GST_VERSION=	1.22.4
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
