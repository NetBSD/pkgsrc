# $NetBSD: Makefile,v 1.21 2017/12/10 22:51:05 spz Exp $

DISTNAME=	buffer-1.17
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CPPFLAGS.SunOS+=	-DSYS5
MAKE_ENV.SunOS+=	CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
