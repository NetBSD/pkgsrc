# $NetBSD: Makefile,v 1.18 2008/06/20 01:09:25 joerg Exp $

DISTNAME=	buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Buffer sporadic binary I/O for faster tape use

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC=${CC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
