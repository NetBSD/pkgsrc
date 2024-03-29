# $NetBSD: Makefile,v 1.48 2022/09/18 22:46:25 he Exp $

DISTNAME=	delegate9.9.1
PKGNAME=	delegate-9.9.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.delegate.org/anonftp/DeleGate/
MASTER_SITES+=	ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/delegate.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.delegate.org/delegate/
COMMENT=	General purpose TCP/IP proxy system

MAKE_JOBS_SAFE=		no

# several usages of array[char]: cgi.c was dangerous, see below;
# the other uses are all safe as of version 9.9.1.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

# Prevent undefined behavior when there are more than 127 environment
# variables, in which case argv and the rest of the stack would be
# interpreted as environment variables.
SUBST_CLASSES+=		char
SUBST_STAGE.char=	pre-configure
SUBST_FILES.char=	src/cgi.c
SUBST_SED.char=		-e 's|char ei;|int ei;|'

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		DELEGATE_MANAGER
BUILD_DEFS+=		VARBASE
DELEGATE_MANAGER?=	root@localhost

RCD_SCRIPTS=		delegated
FILES_SUBST+=		ADMIN=${DELEGATE_MANAGER:Q}

OWN_DIRS_PERMS+=	${VARBASE}/spool/delegate/cache ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
OWN_DIRS_PERMS+=	${VARBASE}/spool/delegate-nobody nobody nobody 755

INSTALLATION_DIRS=	sbin share/doc/delegate

MAKE_ENV+=		SHELL=${CONFIG_SHELL}

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
