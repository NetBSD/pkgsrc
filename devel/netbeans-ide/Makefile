# $NetBSD: Makefile,v 1.25 2019/10/12 19:37:47 rillig Exp $
#

DISTNAME=	netbeans-8.2-201609300101
PKGNAME=	netbeans-ide-8.2
PKGREVISION=	4
CATEGORIES=	devel editors
MASTER_SITES=	http://download.netbeans.org/netbeans/${PKGVERSION_NOREV}/final/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://www.netbeans.org/
COMMENT=	NetBeans Java IDE

USE_TOOLS+=		pax
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk7 openjdk7 oracle-jdk8 openjdk8
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/netbeans

USE_TOOLS+=	perl:run
REPLACE_PERL=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl
REPLACE_PYTHON=	extide/ant/bin/runant.py

SHAREDIR=	${PREFIX}/share/${PKGBASE}

CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no
AUTO_MKDIRS=		yes

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
		CREDITS.html README.html netbeans.css \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC} && pax -rwpm * ${DESTDIR}${SHAREDIR}
	${LN} -sf ${SHAREDIR}/bin/netbeans ${DESTDIR}${PREFIX}/bin/netbeans

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
