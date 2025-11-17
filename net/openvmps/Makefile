# $NetBSD: Makefile,v 1.11 2025/11/17 11:01:15 wiz Exp $

DISTNAME=	vmpsd-1.3
PKGNAME=	openvmps-1.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vmps/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://vmps.sourceforge.net/
COMMENT=	GPL implementation of the VMPS protocol

WRKSRC=		${WRKDIR}/vmpsd

GNU_CONFIGURE=	YES

EGDIR=		${PREFIX}/share/examples/openvmps
RCD_SCRIPTS=	vmpsd
CONF_FILES=	${EGDIR}/vlan.db ${PKG_SYSCONFDIR}/vlan.db

.include "../../mk/bsd.pkg.mk"
