# $NetBSD: Makefile,v 1.1.1.1 2016/01/11 10:52:25 abs Exp $

DISTNAME=	visualvm_138
PKGNAME=	visualvm-1.3.8
CATEGORIES=	devel
MASTER_SITES=	https://java.net/projects/visualvm/downloads/download/release138/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://java.net/projects/visualvm/downloads/download/release138/
COMMENT=	Monitor, profile, take and browse java thread dumps
LICENSE=	gnu-gpl-v2

USE_JAVA=	yes
USE_JAVA2=	8
USE_LANGUAGES=	# none
USE_TOOLS+=	find pax

NO_CONFIGURE=	yes

VISUALVMDIR=	lib/visualvm

# Contains shlibs for many different arches
CHECK_SHLIBS_SUPPORTED= no

INSTALLATION_DIRS= bin ${VISUALVMDIR}

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' -e  's|@JAVA_HOME@|${PKG_JAVA_HOME}|g' ${FILESDIR}/visualvm.sh > ${WRKDIR}/visualvm.sh

do-install:
	cd ${WRKSRC} && ${FIND} . -type f ! -name '*.orig' | ${PAX} -rw ${DESTDIR}${PREFIX}/${VISUALVMDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/visualvm.sh ${DESTDIR}${PREFIX}/bin/visualvm

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
