# $NetBSD: Makefile,v 1.7 2008/05/26 02:13:18 joerg Exp $

DISTNAME=		jave_6.0_M7
PKGNAME=		jave-6.0m7
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://www.jave.de/developer/ http://www.jave.de/figlet/
EXTRACT_SUFX=		.zip
DISTFILES=		jave_6.0_M7${EXTRACT_SUFX} figletfonts37${EXTRACT_SUFX}

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.jave.de/
COMMENT=		Java ASCII Versatile Editor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk14 sun-jdk15

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin sjare/jave

post-extract:
	${MKDIR} ${WRKDIR:Q}/.workdir
	${MV} ${WRKDIR:Q}/* ${WRKDIR:Q}/.workdir/

do-build:
	${SED}	-e "s#@PKG_JAVA_HOME@#${PKG_JAVA_HOME}#g"	\
		-e "s#@PREFIX@#${PREFIX}#g"			\
		< ${FILESDIR:Q}/jave > ${WRKDIR:Q}/jave

do-install:
	${INSTALL_SCRIPT} ${WRKDIR:Q}/jave ${DESTDIR}${PREFIX}/bin
	(cd ${WRKDIR:Q}/.workdir && pax -rw * ${DESTDIR}${PREFIX}/share/jave)

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
