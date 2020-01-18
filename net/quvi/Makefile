# $NetBSD: Makefile,v 1.36 2020/01/18 21:50:24 jperkin Exp $
#

DISTNAME=	quvi-0.4.2
PKGREVISION=	20
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Command line tool for parsing video links
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.2
.include "../../www/curl/buildlink3.mk"
.include "../../net/libquvi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
