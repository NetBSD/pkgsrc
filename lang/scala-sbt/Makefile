# $NetBSD: Makefile,v 1.2 2019/07/04 13:46:46 ryoon Exp $

DISTNAME=	sbt-1.2.8
PKGNAME=	scala-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://piccolo.link/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.scala-sbt.org/
COMMENT=	Interactive build tool for Scala language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/sbt
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_JAVA2=	8
NO_BUILD=	yes

SUBST_CLASSES+=		path
SUBST_FILES.path=	bin/sbt bin/sbt-launch-lib.bash
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fix pathes for pkgsrc installation
SUBST_VARS.path=	PREFIX JAVA_BINPREFIX

USE_TOOLS+=	bash:run pax
REPLACE_BASH+=	bin/sbt bin/sbt-launch-lib.bash

INSTALLATION_DIRS+=	bin share/sbt

do-install:
	cd ${WRKDIR} && ${FIND} sbt -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -s ../share/sbt/bin/sbt .

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
