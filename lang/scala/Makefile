# $NetBSD: Makefile,v 1.17 2020/04/04 04:19:36 mef Exp $

DISTNAME=	scala-2.13.0
CATEGORIES=	lang
MASTER_SITES=	http://www.scala-lang.org/files/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yyamano@NetBSD.org
HOMEPAGE=	https://www.scala-lang.org/
COMMENT=	Scala is a multi-paradigm programming language
LICENSE=	apache-2.0

USE_JAVA=	run
USE_JAVA2=	8
NO_BUILD=	yes

USE_TOOLS+=	bash:run tar
REPLACE_BASH+=	bin/fsc bin/scala bin/scalac \
		bin/scaladoc bin/scalap

SCALA_HOME=	${PREFIX}/share/${DISTNAME}

SUBST_CLASSES+=		scala
SUBST_FILES.scala=	bin/fsc bin/scala bin/scalac bin/scaladoc bin/scalap
SUBST_STAGE.scala=	pre-configure
SUBST_VARS.scala=	PREFIX
SUBST_SED.scala+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_VARS.scala+=	SCALA_HOME

PLIST_SUBST+=	DISTNAME=${DISTNAME}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/${DISTNAME}

post-extract:
	@${RM}  ${WRKSRC}/bin/*.bat

do-install:
	@${RM} -f ${WRKSRC}/bin/*.orig
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@cd ${WRKSRC} && ${TAR} cf - doc lib | ${TAR} xf - -C ${DESTDIR}${SCALA_HOME}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
