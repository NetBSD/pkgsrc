# $NetBSD: Makefile,v 1.16 2015/08/10 10:04:44 asau Exp $
#

DISTNAME=	netbeans-8.0.2-201411181905
PKGNAME=	netbeans-ide-8.0.2
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.netbeans.org/netbeans/8.0.2/final/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://www.netbeans.org/
COMMENT=	NetBeans Java IDE

USE_TOOLS+=	pax
USE_JAVA=	run
PKG_JVMS_ACCEPTED=  sun-jdk15 sun-jdk6 sun-jdk7 openjdk7 openjdk8
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/netbeans

USE_TOOLS+=	perl:run
REPLACE_PERL=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl
REPLACE_PYTHON=	extide/ant/bin/runant.py

SHAREDIR=	${PREFIX}/share/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/html/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	for f in CREDITS.html README.html netbeans.css; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${DOCDIR}; \
	done
	cd ${WRKSRC} && pax -rwpm * ${DESTDIR}${SHAREDIR}
	${LN} -sf ${SHAREDIR}/bin/netbeans ${DESTDIR}${PREFIX}/bin/netbeans

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
