# $NetBSD: Makefile,v 1.6 2008/07/14 12:56:10 joerg Exp $

DISTNAME=	ipgrab-0.9.9
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
