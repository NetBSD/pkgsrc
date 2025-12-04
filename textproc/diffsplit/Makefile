# $NetBSD: Makefile,v 1.15 2025/12/04 13:04:39 wiz Exp $

DISTNAME=	diffsplit
PKGNAME=	diffsplit-1.0
PKGREVISION=	11
CATEGORIES=	textproc devel misc
MASTER_SITES=	https://www.pathname.com/~quinlan/software/diffsplit/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pathname.com/~quinlan/software/diffsplit/
COMMENT=	Splits a unified diff into pieces which patch one file each

NO_BUILD=	YES
WRKSRC=		${WRKDIR}
REPLACE_PERL=	diffsplit
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/diffsplit ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/diffsplit ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
