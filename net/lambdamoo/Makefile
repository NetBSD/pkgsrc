# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:55:42 jlam Exp $

DISTNAME=		LambdaMOO-1.8.1
PKGNAME=		lambdamoo-1.8.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.place.org/pub/moo/ \
			${MASTER_SITE_SOURCEFORGE:=lambdamoo/} \
			ftp://ftp.kanga.nu/pub/mirrors/download.sourceforge.net/lambdamoo/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ccs.neu.edu/home/eostrom/muds/lambdamoo.html
COMMENT=		The definitive MOO software

DEPENDS+=		lambdamoo-core>=990412:../../net/lambdamoo-core
DEPENDS+=		lambdamoo-doc>=1.8.0p6:../../net/lambdamoo-doc

LAMBDAMOO_USER?=	lambdamoo
LAMBDAMOO_GROUP?=	lambdamoo
LAMBDAMOO_HOME?=	${PREFIX}/share/${LAMBDAMOO_USER}

PKG_GROUPS=		${LAMBDAMOO_GROUP}
PKG_USERS=		${LAMBDAMOO_USER}:${LAMBDAMOO_GROUP}
_PKG_USER_HOME=		${LAMBDAMOO_HOME}
_PKG_USER_SHELL=	${SH}
DEINSTALL_EXTRA_TMPL=   ${WRKDIR}/DEINSTALL.out

ALL_TARGET=
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/MOO-1.8.1

post-build:
	${MV} ${WRKSRC}/restart.sh ${WRKSRC}/restart.sh.in
	${SED} <${WRKSRC}/restart.sh.in >${WRKSRC}/restart.sh	\
		"s|__PREFIX__|${PREFIX}|g"
	${SED} <${PKGDIR}/DEINSTALL >${DEINSTALL_EXTRA_TMPL}	\
		"s|__LAMBDAMOO_HOME__|${LAMBDAMOO_HOME}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_SCRIPT} ${WRKSRC}/restart.sh ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/Minimal.db ${PREFIX}/share/lambdamoo
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} \
		${WRKSRC}/README \
		${WRKSRC}/README.Minimal \
		${PREFIX}/share/doc/lambdamoo/

post-install:
	${CHOWN} -R ${LAMBDAMOO_USER}:${LAMBDAMOO_GROUP} ${LAMBDAMOO_HOME}
	${CHMOD} u+w ${LAMBDAMOO_HOME}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
