# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:29 jlam Exp $
#

DISTNAME=	xnap-2.0
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xnap/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xnap.sourceforge.net/
COMMENT=	Java filesharing client with support for OpenNap

NO_BUILD=       yes

INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKSRC} && ${MV} xnap.sh xnap.sh.in

pre-configure:
	cd ${WRKSRC} && ${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' < xnap.sh.in > xnap.sh

do-install:
	${CP} ${WRKSRC}/xnap.sh ${PREFIX}/bin/xnap
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/xnap
	${CP} ${WRKSRC}/xnap.jar ${PREFIX}/share/xnap/xnap.jar
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/xnap
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/xnap
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/xnap ${PREFIX}/share/doc/xnap

.include "../../mk/java-vm.mk"

.if ${PKG_JVM} == "jdk" || ${PKG_JVM} == "kaffe"
DEPENDS+=	swing-[0-9]*:../../x11/swing
.endif

.include "../../mk/bsd.pkg.mk"
