# $NetBSD: Makefile,v 1.1.1.1 2004/02/18 18:48:43 minskim Exp $

DISTNAME=	ipgrab-0.9.8
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_MAKEINFO=	yes
INFO_FILES=	ipgrab.info

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
