# $NetBSD: Makefile,v 1.6 2003/06/23 10:42:14 seb Exp $

DISTNAME=		dmalloc-4.8.2
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC

INSTALL_TARGET=		install installinfo

USE_NEW_TEXINFO=	YES
INFO_FILES=		dmalloc.info

.include "../../mk/bsd.pkg.mk"
