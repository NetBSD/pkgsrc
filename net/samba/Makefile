# $NetBSD: Makefile,v 1.19 1999/01/29 10:39:18 bouyer Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/10/23 15:17:43 max Exp
#

DISTNAME=	samba-1.9.18p10
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/samba/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://samba.anu.edu.au/samba/samba.html

CONFLICTS=      samba-1.9.18p8 samba-2.*

WRKSRC=		${WRKDIR}/${DISTNAME}/source

.include "../../mk/bsd.prefs.mk"

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/etc/smb.conf.sample
SAMBA_LOGDIR=	/var/log
SAMBA_LOCKDIR=	/var/run/samba
SAMBA_ETCDIR?=	/etc/samba
SAMBA_PRIVATE?=	${SAMBA_ETCDIR}/private

MAKE_ENV+=	ETCDIR=${SAMBA_ETCDIR} PRIVDIR=${SAMBA_PRIVATE}
MAKE_ENV+=	LOGDIR=${SAMBA_LOGDIR} LOCKDIR=${SAMBA_LOCKDIR}

PLIST_SRC= ${WRKDIR}/.PLIST-src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	for i in ${WRKDIR}/${DISTNAME}/docs/*.txt ${WRKDIR}/${DISTNAME}/docs/README* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba; \
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq; \
	done
.endif
	${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";		\
	${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT};			\
	${ECHO} 'smbd=${PREFIX}/sbin/smbd' >> ${STARTUP_SCRIPT};	\
	${ECHO} 'nmbd=${PREFIX}/sbin/nmbd' >> ${STARTUP_SCRIPT};	\
	${ECHO} 'if [ -f $$smbd ]; then' >> ${STARTUP_SCRIPT};		\
	${ECHO} "	${ECHO} -n ' Samba'" >> ${STARTUP_SCRIPT};	\
	${ECHO} '	$$smbd -D' >> ${STARTUP_SCRIPT};		\
	${ECHO} '	$$nmbd -D' >> ${STARTUP_SCRIPT};		\
	${ECHO} "fi" >> ${STARTUP_SCRIPT};				\
	chmod 755 ${STARTUP_SCRIPT};					\
	chown bin:bin ${STARTUP_SCRIPT};
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's:__LOGDIR__:${SAMBA_LOGDIR}:g'		\
		    -e 's:__SAMBA_LOCKDIR__:${SAMBA_LOCKDIR}:g'		\
			${FILESDIR}/smb.conf.sample			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/mksmbpasswd.sh ${PREFIX}/bin
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		chown root:wheel ${SAMBA_PRIVATE} ;			\
		chmod 700 ${SAMBA_PRIVATE} ;				\
	fi
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${PREFIX}/bin/mksmbpasswd.sh > ${SAMBA_PRIVATE}/smbpasswd ; \
		chmod 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	${SED} -e 's:__SAMBA_PRIVATE__:${SAMBA_PRIVATE}:g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
