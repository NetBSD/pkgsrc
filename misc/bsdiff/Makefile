# $NetBSD: Makefile,v 1.1.1.1 2003/12/30 17:34:45 cjep Exp $
#

DISTNAME=		bsdiff-4.1
CATEGORIES=		misc
MASTER_SITES=		http://www.daemonology.net/bsdiff/

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.daemonology.net/bsdiff/
COMMENT=		Size efficient binary diff and patch tools

USE_BUILDLINK2=		yes

.if !exists(/usr/bin/bzip2)
MAKE_ENV+=		BZIP2=${LOCALBASE}/bin/bzip2
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
