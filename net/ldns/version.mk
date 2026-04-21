# $NetBSD: version.mk,v 1.3 2026/04/21 09:19:56 adam Exp $
# used by net/ldns/Makefile
# used by net/drill/Makefile

LDNS_VERSION=	1.9.0

DISTNAME=	ldns-${LDNS_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/ldns/

DISTINFO_FILE=	${.CURDIR}/../../net/ldns/distinfo
PATCHDIR=	${.CURDIR}/../../net/ldns/patches
