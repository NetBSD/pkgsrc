# $NetBSD: Makefile,v 1.15 2023/12/23 09:15:58 zafer Exp $

DISTNAME=	qident-1.2
CATEGORIES=	security net
MASTER_SITES=	https://www.aydogan.net/distfiles/security/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.hairylemon.org/~ad/software/qident/
COMMENT=	Small program to query an ident protocol server (rfc1413)

USE_BSD_MAKEFILE=	YES
USE_TOOLS+=		groff nroff

LDFLAGS.SunOS+=	-lnsl -lresolv

MANCOMPRESSED_IF_MANZ=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../security/libident/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
