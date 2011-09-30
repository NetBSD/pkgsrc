# $NetBSD: Makefile,v 1.5 2011/09/30 07:56:13 yyamano Exp $

DISTNAME=	scala-2.9.1
CATEGORIES=	lang
MASTER_SITES=	http://www.scala-lang.org/downloads/distrib/files/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.final${EXTRACT_SUFX}

MAINTAINER=	yyamano@NetBSD.org
HOMEPAGE=	http://www.scala-lang.org/
COMMENT=	Scala is a multi-paradigm programming language

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}.final

USE_JAVA=	run
USE_JAVA2=	1.5
NO_BUILD=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	bin/fsc bin/sbaz-setup bin/scala bin/scalac \
		bin/scaladoc bin/scalap

SCALA_HOME=	${PREFIX}/share/${DISTNAME}

SUBST_CLASSES+=		scala
SUBST_FILES.scala=	bin/fsc bin/sbaz bin/sbaz-setup
SUBST_FILES.scala+=	bin/scala bin/scalac bin/scaladoc bin/scalap
SUBST_STAGE.scala=	pre-configure
SUBST_SED.scala=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.scala+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.scala+=	-e 's,@SCALA_HOME@,${SCALA_HOME},g'

PLIST_SUBST+=	DISTNAME=${DISTNAME}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/${DISTNAME}

post-extract:
	@${RM}  ${WRKSRC}/bin/*.bat

do-install:
	@${RM}  ${WRKSRC}/bin/*.orig
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@cd ${WRKSRC} && ${TAR} cf - doc lib meta misc src | ${TAR} xf - -C ${DESTDIR}${SCALA_HOME}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
