# $NetBSD: version.mk,v 1.22 2025/02/05 13:23:33 adam Exp $

GST_VERSION=	1.24.12
.if ${GST_VERSION:E} < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
.else
SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
.endif
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
