# $NetBSD: version.mk,v 1.34 2026/08/06 19:11:10 adam Exp $

GST_VERSION=	1.28.6
.if ${GST_VERSION:E} < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
.else
SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
.endif
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
