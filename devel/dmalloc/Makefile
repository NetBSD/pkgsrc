# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 18:44:06 jlam Exp $

DISTNAME=		dmalloc-4.8.2
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC

INSTALL_TARGET=		install installinfo

INFO_FILES=		dmalloc.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
