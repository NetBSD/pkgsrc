# $NetBSD: version.mk,v 1.13 2024/05/13 09:05:54 adam Exp $

GST_VERSION=	1.24.3
# if ${PATCH} is < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
#else
#SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
