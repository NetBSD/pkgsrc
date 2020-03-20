# $NetBSD: Makefile,v 1.18 2020/03/20 11:58:12 nia Exp $
#

DISTNAME=	xnap-2.0
PKGREVISION=	2
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xnap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xnap.sourceforge.net/
COMMENT=	Java filesharing client with support for OpenNap

USE_JAVA=		run
PKG_JVMS_ACCEPTED=	1.4

NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/xnap share/doc/xnap

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	fixing java path
SUBST_FILES.path=	xnap.sh
SUBST_SED.path=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME}/,g'
SUBST_VARS.path=	PREFIX

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xnap.sh ${DESTDIR}${PREFIX}/bin/xnap
	${INSTALL_DATA} ${WRKSRC}/xnap.jar ${DESTDIR}${PREFIX}/share/xnap/xnap.jar
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xnap

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
