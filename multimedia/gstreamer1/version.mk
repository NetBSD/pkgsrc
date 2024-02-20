# $NetBSD: version.mk,v 1.10 2024/02/20 20:40:07 wiz Exp $

GST_VERSION=	1.22.10
# if ${PATCH} is < 10
#SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
#else
SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
