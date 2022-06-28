# $NetBSD: Makefile,v 1.13 2022/06/28 11:36:09 wiz Exp $
# FreeBSD Id: ports/textproc/diffsplit/Makefile,v 1.7 2006/12/22 13:43:54 barner Exp

DISTNAME=	diffsplit
PKGNAME=	diffsplit-1.0
PKGREVISION=	11
CATEGORIES=	textproc devel misc
MASTER_SITES=	http://www.pathname.com/~quinlan/software/diffsplit/
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pathname.com/~quinlan/software/diffsplit/
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
