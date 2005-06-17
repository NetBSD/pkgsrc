# $NetBSD: Makefile,v 1.20 2005/06/17 03:50:30 jlam Exp $
#

DISTNAME=	papersize-1.0.8
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Manipulate the default papersize in certain packages

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_PKGINSTALL=	yes

INSTALLATION_DIRS=	bin man/man1

do-build:
	@for f in setpapersize getpapersize; do			\
		${SED} ${FILES_SUBST_SED}			\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setpapersize ${PREFIX}/bin/setpapersize
	${INSTALL_SCRIPT} ${WRKSRC}/getpapersize ${PREFIX}/bin/getpapersize
	${INSTALL_MAN} ${FILESDIR}/getpapersize.1 ${PREFIX}/man/man1/getpapersize.1
	${INSTALL_MAN} ${FILESDIR}/setpapersize.1 ${PREFIX}/man/man1/setpapersize.1

.include "../../mk/bsd.pkg.mk"
