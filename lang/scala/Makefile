# $NetBSD: Makefile,v 1.1.1.1 2010/01/23 10:50:45 yyamano Exp $

DISTNAME=	scala-2.7.7
CATEGORIES=	lang
MASTER_SITES=	http://www.scala-lang.org/downloads/distrib/files/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.final${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/${DISTNAME}.final

MAINTAINER=	yyamano@NetBSD.org
HOMEPAGE=	http://www.scala-lang.org/
COMMENT=	Scala is a multi-paradigm programming language

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_JAVA2=	1.5
NO_BUILD=	yes

SCALA_HOME=	${DESTDIR}${PREFIX}/share/${DISTNAME}

SUBST_CLASSES+=		scala
SUBST_FILES.scala=	bin/fsc bin/sbaz bin/sbaz-setup
SUBST_FILES.scala+=	bin/scala bin/scalac bin/scaladoc
SUBST_STAGE.scala=	pre-configure
SUBST_SED.scala=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.scala+=	-e 's,@SCALA_HOME@,${SCALA_HOME},g'

PLIST_SUBST+=	DISTNAME=${DISTNAME}

INSTALLATION_DIRS=	bin man share/${DISTNAME}

post-extract:
	@${RM}  ${WRKSRC}/bin/*.bat

do-install:
	@${RM}  ${WRKSRC}/bin/*.orig
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/man/man1
	@cd ${WRKSRC} && ${TAR} cf - doc lib meta misc src | ${TAR} xf - -C ${SCALA_HOME}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
