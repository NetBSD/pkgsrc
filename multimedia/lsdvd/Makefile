# $NetBSD: Makefile,v 1.20 2017/08/16 20:21:12 wiz Exp $

DISTNAME=	lsdvd-0.17
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
