# $NetBSD: Makefile,v 1.12 2010/02/11 23:23:11 joerg Exp $
#

DISTNAME=	xnap-2.0
PKGREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xnap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xnap.sourceforge.net/
COMMENT=	Java filesharing client with support for OpenNap

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/xnap share/doc/xnap

post-extract:
	cd ${WRKSRC} && ${MV} xnap.sh xnap.sh.in

pre-configure:
	cd ${WRKSRC} && ${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' < xnap.sh.in > xnap.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xnap.sh ${DESTDIR}${PREFIX}/bin/xnap
	${INSTALL_DATA} ${WRKSRC}/xnap.jar ${PREFIX}/share/xnap/xnap.jar
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xnap

.include "../../mk/java-vm.mk"

.if ${PKG_JVM} == "jdk" || ${PKG_JVM} == "kaffe"
DEPENDS+=	swing-[0-9]*:../../x11/swing
.endif

.include "../../mk/bsd.pkg.mk"
