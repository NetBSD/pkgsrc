# $NetBSD: Makefile,v 1.21 2001/04/07 01:53:24 kim Exp $
# FreeBSD Id: Makefile,v 1.24 1997/05/14 14:40:34 ache Exp
#

DISTNAME=	procmail-3.15
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.procmail.org/
COMMENT=	Local mail delivery agent

INSTALL_TARGET=	install-suid install.man
MAKE_ENV=	SHELL=/bin/sh

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PROCMAIL_MAILSPOOLHOME

.ifdef(PROCMAIL_MAILSPOOLHOME)
pre-configure:
	${ECHO} "#define MAILSPOOLHOME \"/${PROCMAIL_MAILSPOOLHOME}\""	\
	>> ${WRKSRC}/src/authenticate.h
.endif

.if ${OPSYS} == "SunOS"
do-install:
	cd ${WRKSRC}/new;						\
	for f in procmail formail lockfile; do				\
		${INSTALL_PROGRAM} $$f ${LOCALBASE}/bin/$$f;		\
	done;								\
	${INSTALL_SCRIPT} mailstat ${LOCALBASE}/bin/mailstat;		\
	for f in procmail.1 formail.1 lockfile.1; do			\
		${INSTALL_MAN} $$f ${LOCALBASE}/man/man1/$$f;		\
	done;								\
	for f in procmailex.5 procmailrc.5 procmailsc.5; do		\
		${INSTALL_MAN} $$f ${LOCALBASE}/man/man5/$$f;		\
	done
	${SH} ${WRKSRC}/suid.sh
.endif

.include "../../mk/bsd.pkg.mk"
