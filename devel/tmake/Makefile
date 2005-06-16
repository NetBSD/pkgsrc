# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:48 jlam Exp $
#

DISTNAME=	tmake-1.11
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.trolltech.com/products/download/freebies/tmake.html
COMMENT=	Cross-platform Makefile Tool

RESTRICTED=		No paid redistribution
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_PERL5=		YES

TMAKEPATH=	${PREFIX}/lib/tmake/netbsd-g++
GLBASE=		${X11BASE}

INSTALLATION_DIRS=	bin

do-build:
	${MV} ${WRKSRC}/bin/tmake ${WRKSRC}/bin/tmake.BAK
	${SED}  -e 's;@PERL5@;${PERL5};g' \
		-e 's;@TMAKEPATH@;${TMAKEPATH};g' \
		${WRKSRC}/bin/tmake.BAK > ${WRKSRC}/bin/tmake
	${RM} -f ${WRKSRC}/bin/tmake.BAK
	${MV} ${WRKSRC}/lib/netbsd-g++/tmake.conf ${WRKSRC}/lib/netbsd-g++/tmake.conf.BAK
	${SED}  -e 's;@LOCALBASE@;${LOCALBASE};g' \
		-e 's;@X11BASE@;${X11BASE};g' \
		-e 's;@GLBASE@;${GLBASE};g' \
		${WRKSRC}/lib/netbsd-g++/tmake.conf.BAK > ${WRKSRC}/lib/netbsd-g++/tmake.conf
	${RM} -f ${WRKSRC}/lib/netbsd-g++/tmake.conf.BAK
	${MV} ${WRKSRC}/bin/progen ${WRKSRC}/bin/progen.BAK
	${SED} 's;/usr/bin/perl;${PERL5};g' \
		${WRKSRC}/bin/progen.BAK > ${WRKSRC}/bin/progen
	${RM} -f ${WRKSRC}/bin/progen.BAK

# avoid installing .orig files
pre-install:
	${RM} -f ${WRKSRC}/lib/netbsd-g++/*.orig
	${RM} -f ${WRKSRC}/lib/unix/*.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/progen ${PREFIX}/bin/progen
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmake ${PREFIX}/bin/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tmake
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tmake
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA} ${WRKSRC}/lib/netbsd-g++/* ${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tmake/unix
	${INSTALL_DATA} ${WRKSRC}/lib/unix/* ${PREFIX}/lib/tmake/unix

.include "../../mk/bsd.pkg.mk"
