# $NetBSD: Makefile,v 1.33 2023/12/11 23:52:52 zafer Exp $
#

DISTNAME=		bicom101
PKGNAME=		bicom-1.01
PKGREVISION=		2
CATEGORIES=		archivers
MASTER_SITES=		https://www.aydogan.net/distfiles/archivers/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www3.sympatico.ca/mt0000/bicom/bicom.html
COMMENT=		Data compressor in the PPM family
LICENSE=		bicom-license

RESTRICTED=		No commercial use without prior arrangement, no permission to distribute granted.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin share/doc/bicom

do-build:
	set -e;								\
	for i in bialib bicom; do					\
		cd ${WRKSRC}/"$$i" &&					\
		for f in *.cpp; do					\
			${CXX} ${CXXFLAGS} -I./ -I../bialib		\
				-c "$$f";				\
		done;							\
	done
	cd ${WRKSRC}/bicom &&						\
		${CXX} ${CXXFLAGS} ${LDFLAGS}				\
			-o bicom *.o ../bialib/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/bicom/readme.txt

.include "../../mk/bsd.pkg.mk"
