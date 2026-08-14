# $NetBSD: Makefile,v 1.3 2026/08/14 12:46:48 ryoon Exp $

DISTNAME=	leiningen-2.12.0
PKGNAME=	clojure-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=		${MASTER_SITE_CODEBERG:=leiningen/}
CODEBERG_PROJECT=	leiningen
CODEBERG_TAG=		${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://leiningen.org/
COMMENT=	Automating Clojure projects
LICENSE=	epl-v1.0

LEINJAR=		leiningen-${PKGVERSION_NOREV}-standalone.jar
DISTFILES=		${DEFAULT_DISTFILES} ${LEINJAR}
SITES.leiningen-2.12.0-standalone.jar=	https://codeberg.org/leiningen/leiningen/releases/download/${PKGVERSION_NOREV}/

EXTACT_ONLY=	${DEFAULT_DISTFILES}

DEPENDS+=	clojure-[0-9]*:../../lang/clojure

WRKSRC=		${WRKDIR}/leiningen
USE_LANGUAGES=	# none

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	8

REPLACE_SH=	bin/lein-pkg

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting PREFIX
SUBST_FILES.prefix+=	bin/lein-pkg
SUBST_VARS.prefix+=	PREFIX PKG_JVM

INSTALLATION_DIRS+=	bin share/bash-completion/completions 
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/zsh/site-functions
INSTALLATION_DIRS+=	share/leiningen

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lein-pkg \
		${DESTDIR}${PREFIX}/bin/lein
	${INSTALL_DATA} ${WRKSRC}/bash_completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/lein
	${INSTALL_DATA} ${WRKSRC}/zsh_completion.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_lein
	${INSTALL_DATA} ${WRKSRC}/doc/lein.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKDIR}/${LEINJAR} \
		${DESTDIR}${PREFIX}/share/leiningen

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
