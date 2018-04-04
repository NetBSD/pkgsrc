# $NetBSD: Makefile,v 1.1 2018/04/04 16:07:21 pho Exp $

DISTNAME=	cfr_0_125
PKGNAME=	${DISTNAME:S/_/-/:S/_/./g}
CATEGORIES=	devel
MASTER_SITES=	http://www.benf.org/other/cfr/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.benf.org/other/cfr/
COMMENT=	Another java decompiler
LICENSE=	mit

NO_CONFIGURE=	yes
USE_JAVA=	run
USE_JAVA2=	6
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} -f "$$extract_file" "${WRKSRC}"

LIBDIR=		lib/java/cfr
INSTALLATION_DIRS=	bin ${LIBDIR}

# CFR tends to consume a huge amount of memory:
# -Xmx<size>  maximum Java heap size
JVM_ARGS=	-Xmx4G

do-build:
	${PRINTF} '#!%s\nexec "%s" %s -jar "%s" "$$@"\n' \
		"${SH}" \
		"${JAVA_BINPREFIX}-java" \
		"${JVM_ARGS}" \
		"${PREFIX}/${LIBDIR}/${DISTNAME}${EXTRACT_SUFX}" \
		> "${WRKSRC}/cfr"

do-install:
	${INSTALL_SCRIPT} "${WRKSRC}/cfr" "${DESTDIR}${PREFIX}/bin"
	${INSTALL_DATA} "${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}" "${DESTDIR}${PREFIX}/${LIBDIR}"

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
