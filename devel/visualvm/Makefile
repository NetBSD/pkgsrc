# $NetBSD: Makefile,v 1.8 2024/05/08 10:50:04 abs Exp $

DISTNAME=	visualvm_218
PKGNAME=	visualvm-2.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oracle/}
GITHUB_RELEASE=	${PKGNAME:S:visualvm-::}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://visualvm.github.io/
COMMENT=	Monitor, profile, take and browse java thread dumps
LICENSE=	gnu-gpl-v2

USE_JAVA2=	8
USE_LANGUAGES=	# none
USE_TOOLS+=	find pax

NO_CONFIGURE=	yes

VISUALVMDIR=	lib/visualvm

# Contains shlibs for many different arches
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
CHECK_RELRO_SUPPORTED=	no
CHECK_PIE_SUPPORTED=	no

INSTALLATION_DIRS=	bin ${VISUALVMDIR}

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' -e  's|@JAVA_HOME@|${PKG_JAVA_HOME}|g' ${FILESDIR}/visualvm.sh > ${WRKDIR}/visualvm.sh

do-install:
	cd ${WRKSRC} && ${FIND} . -type f ! -name '*.orig' | ${PAX} -rw ${DESTDIR}${PREFIX}/${VISUALVMDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/visualvm.sh ${DESTDIR}${PREFIX}/bin/visualvm

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
