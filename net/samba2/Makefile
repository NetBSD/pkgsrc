# $NetBSD: Makefile,v 1.2 1998/12/11 12:05:44 bouyer Exp $

DISTNAME=	samba-2.0.0beta3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.samba.org/pub/samba/beta/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.samba.org/

CONFLICTS=      samba-1.9.18p8 samba-1.9.18p10 samba-2.0.0beta2

WRKSRC=		${WRKDIR}/${DISTNAME}/source
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/etc/smb.conf.sample
SAMBA_LOGDIR=	/var/log
SAMBA_LOCKDIR=	/var/run/samba
SAMBA_ETCDIR?=	/etc/samba
SAMBA_PRIVATE?=	${SAMBA_ETCDIR}/private

MAKE_ENV+=	ETCDIR=${SAMBA_ETCDIR} PRIVATEDIR=${SAMBA_PRIVATE}
MAKE_ENV+=	LOGDIR=${SAMBA_LOGDIR} LOCKDIR=${SAMBA_LOCKDIR}

PLIST_SRC= ${WRKDIR}/.PLIST-src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	${MKDIR} ${PREFIX}/share/doc/samba/textdocs
	for i in ${WRKDIR}/${DISTNAME}/docs/NT4_PlainPassword.reg \
	    ${WRKDIR}/${DISTNAME}/docs/Win95_PlainPassword.reg \
	    ${WRKDIR}/${DISTNAME}/docs/THANKS ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba; \
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq; \
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/textdocs/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/textdocs; \
	done
.endif
	@${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";           \
	${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT};                        \
	${ECHO} 'smbd=${PREFIX}/sbin/smbd' >> ${STARTUP_SCRIPT};        \
	${ECHO} 'nmbd=${PREFIX}/sbin/nmbd' >> ${STARTUP_SCRIPT};        \
	${ECHO} 'if [ -f $$smbd ]; then' >> ${STARTUP_SCRIPT};          \
	${ECHO} "       ${ECHO} -n ' Samba'" >> ${STARTUP_SCRIPT};      \
	${ECHO} '       $$smbd -D' >> ${STARTUP_SCRIPT};                \
	${ECHO} '       $$nmbd -D' >> ${STARTUP_SCRIPT};                \
	${ECHO} "fi" >> ${STARTUP_SCRIPT};                              \
	chmod 755 ${STARTUP_SCRIPT};                                    \
	chown bin.bin ${STARTUP_SCRIPT};
	@if [ ! -f ${SAMPLE_CONFIG} ]; then                             \
		${SED} -e 's:__LOGDIR__:${SAMBA_LOGDIR}:g'              \
		-e 's:__ETCDIR__:${SAMBA_ETCDIR}:g'			\
		-e 's:__PREFIX__:${PREFIX}:g'				\
			${FILESDIR}/smb.conf.sample                     \
			> ${SAMPLE_CONFIG} ;                            \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh ${PREFIX}/bin
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		chown root.wheel ${SAMBA_PRIVATE} ;			\
		chmod 700 ${SAMBA_PRIVATE} ;				\
	fi
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then                   \
		${CAT} /etc/passwd | ${PREFIX}/bin/mksmbpasswd.sh	\
			> ${SAMBA_PRIVATE}/smbpasswd ;			\
		chmod 600 ${SAMBA_PRIVATE}/smbpasswd ;                  \
	fi
	${SED} -e 's:__SAMBA_PRIVATE__:${SAMBA_PRIVATE}:g' ${PKGDIR}/PLIST \
		> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
