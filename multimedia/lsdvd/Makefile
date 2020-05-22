# $NetBSD: Makefile,v 1.21 2020/05/22 12:43:53 adam Exp $

DISTNAME=	lsdvd-0.17
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lsdvd/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lsdvd/
COMMENT=	Application displaying the contents of DVDs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
