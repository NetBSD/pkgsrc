# $NetBSD: Makefile,v 1.11 2012/10/23 18:16:56 asau Exp $

DISTNAME=	qident-1.2
CATEGORIES=	security net
MASTER_SITES=	http://www.hairylemon.org/~ad/software/download/qident/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hairylemon.org/~ad/software/qident/
COMMENT=	Small program to query an ident protocol server (rfc1413)

USE_BSD_MAKEFILE=	YES
USE_TOOLS+=		groff nroff

MANCOMPRESSED_IF_MANZ=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../security/libident/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
