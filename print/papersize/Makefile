# $NetBSD: Makefile,v 1.2 1999/06/16 17:28:25 cgd Exp $
#

DISTNAME=	papersize-1.0.1
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	for f in setpapersize getpapersize; do			\
		${SED} -e 's|@localbase@|${LOCALBASE}|g'	\
		       -e 's|@x11base@|${X11BASE}|g'		\
			${FILESDIR}/$$f > ${WRKSRC}/$$f;	\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setpapersize ${PREFIX}/bin/setpapersize
	${INSTALL_SCRIPT} ${WRKSRC}/getpapersize ${PREFIX}/bin/getpapersize
	${INSTALL_MAN} ${FILESDIR}/getpapersize.1 ${PREFIX}/man/man1/getpapersize.1
	${INSTALL_MAN} ${FILESDIR}/setpapersize.1 ${PREFIX}/man/man1/setpapersize.1

.include "../../mk/bsd.pkg.mk"
