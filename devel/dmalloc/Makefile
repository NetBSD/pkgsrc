# $NetBSD: Makefile,v 1.7 2003/07/15 12:56:36 drochner Exp $

DISTNAME=		dmalloc-5.2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads

INSTALL_TARGET=		install installinfo

USE_NEW_TEXINFO=	YES
INFO_FILES=		dmalloc.info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
