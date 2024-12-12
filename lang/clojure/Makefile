# $NetBSD: Makefile,v 1.11 2024/12/12 14:45:32 ryoon Exp $

DISTNAME=	clojure-tools-1.12.0.1488
PKGNAME=	${DISTNAME:S/-tools//}
CATEGORIES=	lang
MASTER_SITES=	https://download.clojure.org/install/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://clojure.org/
COMMENT=	Dynamic programming language that targets the Java VM
LICENSE=	epl-v1.0

DEPENDS+=	rlwrap-[0-9]*:../../misc/rlwrap

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	8
USE_TOOLS+=	bash

REPLACE_BASH+=	clj
REPLACE_BASH+=	clojure

INSTALLATION_DIRS=	bin \
			clojure \
			clojure/libexec \
			${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/clojure-tools

SUBST_CLASSES+=		set-java
SUBST_STAGE.set-java=	pre-configure
SUBST_MESSAGE.set-java=	Setting JAVA_HOME path.
SUBST_FILES.set-java=	clojure
SUBST_SED.set-java=	-e '/^JAVA_CMD=/s,java,${PKG_JAVA_HOME}/bin/java,'

SUBST_CLASSES+=		set-base
SUBST_STAGE.set-base=	pre-configure
SUBST_MESSAGE.set-base=	Setting package base path.
SUBST_FILES.set-base=	clojure
SUBST_FILES.set-base+=	clj
SUBST_SED.set-base=	-e 's,PREFIX,${PREFIX}/clojure,g'
SUBST_SED.set-base+=	-e 's,BINDIR,${PREFIX}/bin,g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.edn ${DESTDIR}${PREFIX}/clojure
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/clojure/libexec
	${INSTALL_MAN} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/clj ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/clojure ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
