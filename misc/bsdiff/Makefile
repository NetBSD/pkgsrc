# $NetBSD: Makefile,v 1.4 2004/10/03 00:12:58 tv Exp $
#

DISTNAME=		bsdiff-4.2
PKGREVISION=	1
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
