# $NetBSD: Makefile,v 1.32 2003/11/03 22:43:38 kim Exp $
#

DISTNAME=	procmail-3.22
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.procmail.org/
COMMENT=	Local mail delivery agent

USE_BUILDLINK2=	YES
MAKE_ENV+=	SHELL=${SH} CHMOD=${CHMOD}
INSTALL_TARGET=	install-suid install.man

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PROCMAIL_MAILSPOOLHOME PROCMAIL_TRUSTED_IDS

PROCMAIL_TRUSTED_IDS?=\
"root","daemon","uucp","mail","x400","network","list","slist","lists","news",0

pre-configure:
	${ECHO} "#define TRUSTED_IDS {${PROCMAIL_TRUSTED_IDS:Q}}"	\
	>> ${WRKSRC}/config.h
	${ECHO} "#undef ETCRC" >> ${WRKSRC}/config.h
	${ECHO} "#undef ETCRCS" >> ${WRKSRC}/config.h
	${ECHO} "#define ETCRC \"${PKG_SYSCONFDIR}/procmailrc\""	\
	>> ${WRKSRC}/config.h
	${ECHO} "#define ETCRCS \"${PKG_SYSCONFDIR}/procmailrcs/\""	\
	>> ${WRKSRC}/config.h
.ifdef(PROCMAIL_MAILSPOOLHOME)
	${ECHO} "#define MAILSPOOLHOME \"/${PROCMAIL_MAILSPOOLHOME}\""	\
	>> ${WRKSRC}/src/authenticate.h
.endif

.if ${OPSYS} == "SunOS"
do-install:
	cd ${WRKSRC}/new;						\
	for f in procmail formail lockfile; do				\
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin/$$f;		\
	done;								\
	${INSTALL_SCRIPT} mailstat ${PREFIX}/bin/mailstat;		\
	for f in procmail.1 formail.1 lockfile.1; do			\
		${INSTALL_MAN} $$f ${PREFIX}/man/man1/$$f;		\
	done;								\
	for f in procmailex.5 procmailrc.5 procmailsc.5; do		\
		${INSTALL_MAN} $$f ${PREFIX}/man/man5/$$f;		\
	done
	${SH} ${WRKSRC}/suid.sh
.endif

.include "../../mk/bsd.pkg.mk"
