# $NetBSD: Makefile,v 1.3 2000/11/09 05:14:27 itohy Exp $

DISTNAME=	skkinput-2.03
CATEGORIES=	japanese
MASTER_SITES=	http://member.nifty.ne.jp/Tatari_SAKAMOTO/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.yajima.kuis.kyoto-u.ac.jp/staffs/sakamoto/skkinput/skkinput.html

BUILD_DEFS+=	USE_INET6

USE_IMAKE=	YES

# skk.conf uses /usr/pkg (${LOCALBASE}), not /usr/X11R6 (${PREFIX})
MAKE_ENV=	MAKE_FLAGS='EXECBASE=${LOCALBASE}'
PLIST_SUBST=	PKGBASE=${LOCALBASE}

DESCR_SRC=	${WRKDIR}/DESCR
INSTALL_FILE=	${WRKDIR}/INSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/DESCR	>${DESCR_SRC}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/INSTALL	>${INSTALL_FILE}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/MESSAGE	>${MESSAGE_FILE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/skkinput.man ${PREFIX}/man/ja_JP.EUC/man1/skkinput.1
	${MKDIR} ${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/README.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${PREFIX}/share/doc/skkinput
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
