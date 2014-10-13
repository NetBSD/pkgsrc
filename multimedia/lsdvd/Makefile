# $NetBSD: Makefile,v 1.19 2014/10/13 18:29:54 snj Exp $

DISTNAME=	lsdvd-0.17
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lsdvd/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lsdvd/
COMMENT=	Application displaying the contents of DVDs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
