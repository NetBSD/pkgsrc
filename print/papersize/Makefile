# $NetBSD: Makefile,v 1.10 2003/03/29 12:42:16 jmmv Exp $
#

DISTNAME=	papersize-1.0.4
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	Manipulate the default papersize in certain packages

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-build:
	for f in setpapersize getpapersize; do			\
		${SED} -e 's|@localbase@|${LOCALBASE}|g'	\
		       -e 's|@x11prefix@|${X11PREFIX}|g'	\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setpapersize ${PREFIX}/bin/setpapersize
	${INSTALL_SCRIPT} ${WRKSRC}/getpapersize ${PREFIX}/bin/getpapersize
	${INSTALL_MAN} ${FILESDIR}/getpapersize.1 ${PREFIX}/man/man1/getpapersize.1
	${INSTALL_MAN} ${FILESDIR}/setpapersize.1 ${PREFIX}/man/man1/setpapersize.1

.include "../../mk/bsd.pkg.mk"
