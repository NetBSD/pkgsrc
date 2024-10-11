# $NetBSD: Makefile,v 1.58 2024/10/11 06:42:18 nia Exp $

DISTNAME=	procmail-3.24
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=BuGlessRB/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kim@NetBSD.org
HOMEPAGE=	https://github.com/BuGlessRB/procmail
COMMENT=	Local mail delivery agent
LICENSE=	artistic OR gnu-gpl-v2

MAKE_JOBS_SAFE=	no

### Inlining functions (implied by -O3 or higher) cause the strstr() test
### to enter an infinite loop so disable it.  This fixes PR pkg/30999.
CFLAGS+=	-fno-inline-functions

MAKE_ENV+=		SHELL=${SH:Q} CHMOD=${CHMOD:Q}
INSTALL_TARGET=		install-suid install.man
UNLIMIT_RESOURCES=	datasize

SPECIAL_PERMS+=	bin/procmail ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PROCMAIL_MAILSPOOLHOME PROCMAIL_TRUSTED_IDS

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

PROCMAIL_TRUSTED_IDS?= \
	"root","daemon","uucp","mail","x400","network","list","slist","lists","news",0

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/examples/${PKGBASE} share/doc/${PKGBASE}

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

.if ${USE_CROSS_COMPILE:U:tl} == yes
MAKE_FLAGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}

.  if exists(${FILESDIR}/autoconf-${OPSYS}.h.in)
post-configure:
	cd ${WRKSRC} && ${MAKE} init
	${SED} -e s,@PREFIX@,${PREFIX:U},g				\
		-e s,@PKGVERSION@,${PKGVERSION:U},g			\
	    < ${FILESDIR}/autoconf-${OPSYS}.h.in			\
	    > ${WRKSRC}/autoconf.h
.  endif
.endif

.if ${OPSYS} == "SunOS"
do-install:
	cd ${WRKSRC}/new;						\
	for f in procmail formail lockfile; do				\
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/bin/$$f;	\
	done;								\
	${INSTALL_SCRIPT} mailstat ${DESTDIR}${PREFIX}/bin/mailstat;	\
	for f in procmail.1 formail.1 lockfile.1 mailstat.1; do		\
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$f; \
	done;								\
	for f in procmailex.5 procmailrc.5 procmailsc.5; do		\
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/$$f; \
	done
.endif

PKG_DOCS=	FAQ FEATURES HISTORY KNOWN_BUGS README
PKG_EXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

post-install:
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${PKG_EXAMPLES:S|^|${WRKSRC}/examples/|} ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
