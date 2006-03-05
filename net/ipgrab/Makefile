# $NetBSD: Makefile,v 1.4 2006/03/05 16:27:27 jlam Exp $

DISTNAME=	ipgrab-0.9.9
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	ipgrab.info

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
