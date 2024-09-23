# $NetBSD: version.mk,v 1.18 2024/09/23 10:39:41 adam Exp $

GST_VERSION=	1.24.8
# if ${PATCH} is < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
#else
#SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
