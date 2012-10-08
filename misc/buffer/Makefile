# $NetBSD: Makefile,v 1.19 2012/10/08 09:57:17 asau Exp $

DISTNAME=	buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC=${CC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
