# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:13 jlam Exp $
#

DISTNAME=	chmlib-0.37.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://66.93.236.84/%7Ejedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/chmlib-0.37
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-io64

INSTALLATION_DIRS=	include lib

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.endif

.include "../../mk/bsd.pkg.mk"
