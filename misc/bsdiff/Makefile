# $NetBSD: Makefile,v 1.7 2006/11/20 07:30:35 cjep Exp $
#

DISTNAME=		bsdiff-4.3
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

.if !exists(/usr/bin/bzip2)
MAKE_ENV+=		BZIP2=${LOCALBASE}/bin/bzip2
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
