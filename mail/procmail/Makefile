# $NetBSD: Makefile,v 1.26 2001/11/08 12:05:58 bouyer Exp $
#

DISTNAME=	procmail-3.22
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.procmail.org/
COMMENT=	Local mail delivery agent

INSTALL_TARGET=	install-suid install.man
MAKE_ENV=	SHELL=/bin/sh
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PROCMAIL_MAILSPOOLHOME PROCMAIL_TRUSTED_IDS

PROCMAIL_TRUSTED_IDS?=\
"root","daemon","uucp","mail","x400","network","list","slist","lists","news",0

pre-configure:
	${ECHO} "#define TRUSTED_IDS {${PROCMAIL_TRUSTED_IDS:Q}}"	\
	>> ${WRKSRC}/config.h
.ifdef(PROCMAIL_MAILSPOOLHOME)
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
