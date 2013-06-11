# $NetBSD: Makefile,v 1.3 2013/06/11 19:51:27 asau Exp $

DISTNAME=	clojure-1.5.1
CATEGORIES=	lang
MASTER_SITES=	http://repo1.maven.org/maven2/org/clojure/clojure/$(PKGVERSION_NOREV)/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://clojure.org/
COMMENT=	Dynamic programming language that targets the Java VM
LICENSE=	epl-v1.0

NO_BUILD=	yes
USE_JAVA=	run
USE_JAVA2=	1.5
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin \
			share/doc/${PKGNAME_NOREV} \
			lib/java/clojure \
			share/examples/${PKGNAME_NOREV}

CLOJURE_DOCS=	changes.md epl-v10.html readme.txt \
		doc/clojure/pprint/CommonLispFormat.markdown \
		doc/clojure/pprint/PrettyPrinting.markdown

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-install
SUBST_MESSAGE.java=	Set Java
SUBST_FILES.java=	clj.sh
SUBST_SED.java=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.java+=	-e 's,@SH@,${SH},'

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/clj.sh ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGNAME_NOREV}.jar \
		${DESTDIR}${PREFIX}/lib/java/clojure/clojure.jar

	cd ${WRKSRC}/test/clojure && pax -rw -pmp test_clojure \
		${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}/
	${INSTALL_DATA} ${WRKSRC}/test/clojure/test_helper.clj \
		${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}

.for f in ${CLOJURE_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/clj.sh ${DESTDIR}${PREFIX}/bin/clj

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
