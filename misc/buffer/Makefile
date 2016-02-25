# $NetBSD: Makefile,v 1.20 2016/02/25 15:35:30 jperkin Exp $

DISTNAME=	buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CPPFLAGS.SunOS+=	-DSYS5
MAKE_ENV.SunOS+=	CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
