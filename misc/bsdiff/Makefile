# $NetBSD: Makefile,v 1.2 2004/04/24 18:17:06 snj Exp $
#

DISTNAME=		bsdiff-4.1
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

USE_BUILDLINK3=		yes

.if !exists(/usr/bin/bzip2)
MAKE_ENV+=		BZIP2=${LOCALBASE}/bin/bzip2
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
