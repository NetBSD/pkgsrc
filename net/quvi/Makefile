# $NetBSD: Makefile,v 1.42 2021/04/21 13:25:13 adam Exp $
#

DISTNAME=	quvi-0.4.2
PKGREVISION=	24
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
