# $NetBSD: Makefile,v 1.1 2022/11/10 23:25:49 nikita Exp $

DISTNAME=	geteltorito.pl
PKGNAME=	geteltorito-0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://userpages.uni-koblenz.de/~krienke/ftp/noarch/geteltorito/geteltorito/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uni-koblenz.de/~krienke/ftp/noarch/geteltorito/
COMMENT=	El Torito image extractor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	geteltorito.pl
WRKSRC=		${WRKDIR}

NO_BUILD=		yes
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	bin

do-configure:
	${ECHO} "no configure"

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geteltorito.pl ${DESTDIR}${PREFIX}/bin/geteltorito

.include "../../mk/bsd.pkg.mk"
