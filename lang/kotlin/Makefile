# $NetBSD: Makefile,v 1.2 2024/01/06 00:19:30 rillig Exp $

DISTNAME=	kotlin-compiler-1.8.10
PKGNAME=	${DISTNAME:S/-compiler//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=JetBrains/}
GITHUB_PROJECT=	kotlin
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://kotlinlang.org/
COMMENT=	Statically typed programming language for Java VM
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/kotlinc
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run pax

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-configure
SUBST_MESSAGE.java=	Fixing java command path
SUBST_FILES.java+=	bin/kotlinc
SUBST_SED.java+=	-e 's,$$JAVA_HOME/bin/java,${JAVA_BINPREFIX}-java,'
SUBST_SED.java+=	-e 's,JAVACMD:=java,JAVACMD:=${JAVA_BINPREFIX}-java,'

NO_BUILD=	yes

USE_JAVA=	run
USE_JAVA2=	6

REPLACE_BASH+=	bin/*

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && ${FIND} * -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/kotlin
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ../share/kotlin/bin/kotlinc && \
		${LN} -sf ../share/kotlin/bin/kotlinc-jvm && \
		${LN} -sf ../share/kotlin/bin/kotlin && \
		${LN} -sf ../share/kotlin/bin/kapt

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
