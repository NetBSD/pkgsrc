# $NetBSD: version.mk,v 1.33 2026/07/17 13:42:16 adam Exp $

GST_VERSION=	1.28.5
.if ${GST_VERSION:E} < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
.else
SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
.endif
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
