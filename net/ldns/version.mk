# $NetBSD: version.mk,v 1.4 2026/06/11 12:42:25 adam Exp $
# used by net/ldns/Makefile
# used by net/drill/Makefile

LDNS_VERSION=	1.9.2

DISTNAME=	ldns-${LDNS_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/ldns/

DISTINFO_FILE=	${.CURDIR}/../../net/ldns/distinfo
PATCHDIR=	${.CURDIR}/../../net/ldns/patches
