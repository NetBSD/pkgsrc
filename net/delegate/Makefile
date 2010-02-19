# $NetBSD: Makefile,v 1.40 2010/02/19 19:31:12 joerg Exp $

DISTNAME=	delegate9.9.1
PKGNAME=	delegate-9.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.delegate.org/anonftp/DeleGate/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/delegate.org/ 

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.delegate.org/delegate/
COMMENT=	General purpose TCP/IP proxy system

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		DELEGATE_MANAGER
BUILD_DEFS+=		VARBASE
DELEGATE_MANAGER?=	root@localhost

RCD_SCRIPTS=		delegated
FILES_SUBST+=		ADMIN=${DELEGATE_MANAGER:Q}

OWN_DIRS_PERMS+=${VARBASE}/spool/delegate/cache ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
OWN_DIRS_PERMS+=${VARBASE}/spool/delegate-nobody nobody nobody 755

INSTALLATION_DIRS=	sbin share/doc/delegate

pre-build:
	@${ECHO} "ADMIN=${DELEGATE_MANAGER}" >> ${WRKSRC}/DELEGATE_CONF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.htm \
	   ${DESTDIR}${PREFIX}/share/doc/delegate/manual.html
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-en.htm \
	   ${DESTDIR}${PREFIX}/share/doc/delegate/tutorial-en.html
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-jp.htm \
	   ${DESTDIR}${PREFIX}/share/doc/delegate/tutorial-jp.html

.include "../../mk/bsd.pkg.mk"
