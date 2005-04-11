# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:48 tv Exp $

DISTNAME=	ipgrab-0.9.9
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_MAKEINFO=	yes
INFO_FILES=	ipgrab.info

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
