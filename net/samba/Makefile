# $NetBSD: Makefile,v 1.12 1998/08/09 16:14:08 kim Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/10/23 15:17:43 max Exp
#

DISTNAME=	samba-1.9.18p8
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/samba/

MAINTAINER=	tsarna@endicor.com

WRKSRC=		${WRKDIR}/${DISTNAME}/source

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/etc/smb.conf.sample
SAMBA_SPOOL=	/var/spool/samba
SAMBA_LOGDIR=	/var/log
SAMBA_ETCDIR?=	/etc/samba
SAMBA_PRIVATE?=	${SAMBA_ETCDIR}/private

MAKE_ENV+=	ETCDIR=${SAMBA_ETCDIR} PRIVDIR=${SAMBA_PRIVATE}

.include "../../mk/bsd.prefs.mk"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	for i in ${WRKDIR}/${DISTNAME}/docs/*.txt ${WRKDIR}/${DISTNAME}/docs/README* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ; \
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq ; \
	done
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT} ;		\
		${ECHO} 'smbd=${PREFIX}/sbin/smbd' >> ${STARTUP_SCRIPT} ;\
		${ECHO} 'nmbd=${PREFIX}/sbin/nmbd' >> ${STARTUP_SCRIPT} ;\
		${ECHO} 'if [ -f $$smbd ]; then' >> ${STARTUP_SCRIPT}	;\
		${ECHO} "	${ECHO} -n ' Samba'" >> ${STARTUP_SCRIPT} ;\
		${ECHO} '	$$smbd -D' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} '	$$nmbd -D' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} "fi" >> ${STARTUP_SCRIPT} ;			\
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && chmod 1777 ${SAMBA_SPOOL}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's:__SAMBA_SPOOL__:${SAMBA_SPOOL}:g'		\
		    -e 's:__LOGDIR__:${SAMBA_LOGDIR}:g'			\
			${FILESDIR}/smb.conf.sample			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL} -c -m 755 -o bin -g bin ${WRKSRC}/mksmbpasswd.sh ${PREFIX}/bin
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		chown root.wheel ${SAMBA_PRIVATE} ;			\
		chmod 700 ${SAMBA_PRIVATE} ;				\
	fi
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${PREFIX}/bin/mksmbpasswd.sh > ${SAMBA_PRIVATE}/smbpasswd ; \
		chmod 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	chown root.wheel ${PREFIX}/bin/smbpasswd
	chmod 4111 ${PREFIX}/bin/smbpasswd

.include "../../mk/bsd.pkg.mk"
