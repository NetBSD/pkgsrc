# $NetBSD: Makefile,v 1.2 2002/02/18 15:14:09 seb Exp $

DISTNAME=		dmalloc-4.8.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

GNU_CONFIGURE=		yes

INSTALL_TARGET=		install installinfo

INFO_FILES=		dmalloc.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
