# $NetBSD: Makefile,v 1.70 2004/04/20 20:11:34 abs Exp $
#

DISTNAME=	cpuflags-0.66
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* SunOS-*-*

EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

FILES_SUBST+=	PREFIX="${PREFIX}"

do-build:
	${MKDIR} ${WRKSRC}
.for FILE in cpuflags.1 cpuflags.mk
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/${FILE} \
					 > ${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cpuflags.${OPSYS} ${PREFIX}/bin/cpuflags
	${INSTALL_DATA} ${FILESDIR}/optimize_gcc.mk ${PREFIX}/share/mk/optimize_gcc.mk
	${INSTALL_DATA} ${WRKSRC}/cpuflags.mk ${PREFIX}/share/mk/cpuflags.mk
	${INSTALL_MAN} ${WRKSRC}/cpuflags.1 ${PREFIX}/man/man1/cpuflags.1

.include "../../mk/bsd.pkg.mk"
