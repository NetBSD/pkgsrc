# $NetBSD: Makefile,v 1.56 2023/03/01 13:37:26 gdt Exp $

DISTNAME=	procmail-3.22
PKGREVISION=	5
CATEGORIES=	mail
#MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/
# 3.24 is at https://github.com/BuGlessRB/procmail/archive/refs/tags/v3.24.tar.gz

MAINTAINER=	kim@NetBSD.org
HOMEPAGE=	https://github.com/BuGlessRB/procmail
COMMENT=	Local mail delivery agent
LICENSE=	artistic OR gnu-gpl-v2

MAKE_JOBS_SAFE=	no

MAKE_ENV+=		SHELL=${SH:Q} CHMOD=${CHMOD:Q}
INSTALL_TARGET=		install-suid install.man
UNLIMIT_RESOURCES=	datasize

SPECIAL_PERMS+=	bin/procmail ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PROCMAIL_MAILSPOOLHOME PROCMAIL_TRUSTED_IDS

PROCMAIL_TRUSTED_IDS?=\
"root","daemon","uucp","mail","x400","network","list","slist","lists","news",0

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

### Inlining functions (implied by -O3 or higher) cause the strstr() test
### to enter an infinite loop so disable it.  This fixes PR pkg/30999.
CFLAGS+=	-fno-inline-functions

pre-configure:
	${ECHO} "#define TRUSTED_IDS {${PROCMAIL_TRUSTED_IDS:Q}}"	\
	>> ${WRKSRC}/config.h
	${ECHO} "#undef ETCRC" >> ${WRKSRC}/config.h
	${ECHO} "#undef ETCRCS" >> ${WRKSRC}/config.h
	${ECHO} "#define ETCRC \"${PKG_SYSCONFDIR}/procmailrc\""	\
	>> ${WRKSRC}/config.h
	${ECHO} "#define ETCRCS \"${PKG_SYSCONFDIR}/procmailrcs/\""	\
	>> ${WRKSRC}/config.h
.if defined(PROCMAIL_MAILSPOOLHOME)
	${ECHO} "#define MAILSPOOLHOME \"/${PROCMAIL_MAILSPOOLHOME}\""	\
	>> ${WRKSRC}/src/authenticate.h
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}

.if exists(${FILESDIR}/autoconf-${OPSYS}.h.in)
post-configure:
	cd ${WRKSRC} && ${MAKE} init
	${SED} -e s,@PREFIX@,${PREFIX:U},g				\
		-e s,@PKGVERSION@,${PKGVERSION:U},g			\
	    < ${FILESDIR}/autoconf-${OPSYS}.h.in			\
	    > ${WRKSRC}/autoconf.h
.endif
.endif

.if ${OPSYS} == "SunOS"
do-install:
	cd ${WRKSRC}/new;						\
	for f in procmail formail lockfile; do				\
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/bin/$$f;	\
	done;								\
	${INSTALL_SCRIPT} mailstat ${DESTDIR}${PREFIX}/bin/mailstat;	\
	for f in procmail.1 formail.1 lockfile.1; do			\
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$f; \
	done;								\
	for f in procmailex.5 procmailrc.5 procmailsc.5; do		\
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/$$f; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
