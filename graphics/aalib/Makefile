# $NetBSD: Makefile,v 1.4 2002/01/30 11:56:08 agc Exp $
#

DISTNAME=	aalib-1.4rc4
PKGNAME=	aalib-1.4.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

CONFLICTS+=	aalib-x11-[0-9]*

WRKSRC=		${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--with-x11-driver=no

.include "../../mk/bsd.pkg.mk"
