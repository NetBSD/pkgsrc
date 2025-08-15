# $NetBSD: version.mk,v 1.2 2025/08/15 07:07:11 adam Exp $
# used by net/ldns/Makefile
# used by net/drill/Makefile

LDNS_VERSION=	1.8.4

DISTNAME=	ldns-${LDNS_VERSION}
CATEGORIES=	net
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/ldns/

DISTINFO_FILE=	${.CURDIR}/../../net/ldns/distinfo
PATCHDIR=	${.CURDIR}/../../net/ldns/patches
