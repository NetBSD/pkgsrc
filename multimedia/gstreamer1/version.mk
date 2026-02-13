# $NetBSD: version.mk,v 1.28 2026/02/13 18:50:23 wiz Exp $

GST_VERSION=	1.28.0
.if ${GST_VERSION:E} < 10
SHLIBVER=	${GST_VERSION:S/1.//:S/./0/}
.else
SHLIBVER=	${GST_VERSION:S/1.//:S/.//}
.endif
PLIST_SUBST+=	SHLIBVER=${SHLIBVER}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://gstreamer.freedesktop.org/
LICENSE?=	gnu-gpl-v2
