# $NetBSD: Makefile,v 1.30 1999/11/16 21:23:03 jlam Exp $

DISTNAME=	samba-2.0.6
WRKSRC=		${WRKDIR}/${DISTNAME}/source
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.samba.org/pub/samba/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.samba.org/

DEPENDS+=	readline-4.0:../../devel/readline

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/share/examples/samba/smb.conf.sample
SAMBA_LOGDIR=	/var/log
SAMBA_LOCKDIR=	/var/run/samba
SAMBA_ETCDIR?=	/etc/samba
SAMBA_PRIVATE?=	${SAMBA_ETCDIR}/private

MAKE_ENV+=	ETCDIR=${SAMBA_ETCDIR}
MAKE_ENV+=	LOGDIR=${SAMBA_LOGDIR}

CONFIGURE_ARGS= --with-swatdir=${PREFIX}/share/swat \
		--with-lockdir=${SAMBA_LOCKDIR} \
		--with-privatedir=${SAMBA_PRIVATE}

PLIST_SUBST+=	SAMBA_PRIVATE=${SAMBA_PRIVATE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/faq
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/textdocs
	cd ${WRKDIR}/${DISTNAME}/docs; \
	for file in NT4-Locking.txt NT4_PlainPassword.reg	\
	    Win2000_PlainPassword.reg Win95_PlainPassword.reg	\
	    Win98_PlainPassword.reg Win9X-CacheHandling.reg	\
	    WindowsTerminalServer.reg THANKS announce ; do	\
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba; \
	done
	for file in ${WRKDIR}/${DISTNAME}/docs/faq/*.html ; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba/faq; \
	done
	for file in ${WRKDIR}/${DISTNAME}/docs/textdocs/* ; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba/textdocs; \
	done

	${MKDIR} ${PREFIX}/share/examples/samba
	cd ${WRKDIR}/${DISTNAME}/examples; \
	${CP} -R * ${PREFIX}/share/examples/samba
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/samba
	${CHMOD} -R ugo-w ${PREFIX}/share/examples/samba

	${SED}	-e "s:__PREFIX__:${PREFIX}:g" \
		-e "s:__ECHO__:${ECHO}:g" \
		${FILESDIR}/samba.sh \
		> ${WRKDIR}/samba.sh
	${INSTALL_SCRIPT} ${WRKDIR}/samba.sh ${STARTUP_SCRIPT}

	${SED}	-e 's:__LOGDIR__:${SAMBA_LOGDIR}:g' \
		-e 's:__ETCDIR__:${SAMBA_ETCDIR}:g' \
		-e 's:__PREFIX__:${PREFIX}:g' \
		${FILESDIR}/smb.conf.sample \
		> ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${SAMPLE_CONFIG}

	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh ${PREFIX}/bin
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		${CHOWN} root:${BINGRP} ${SAMBA_PRIVATE} ;		\
		${CHMOD} 700 ${SAMBA_PRIVATE} ;				\
	fi
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then                   \
		${CAT} /etc/passwd | ${PREFIX}/bin/mksmbpasswd.sh	\
			> ${SAMBA_PRIVATE}/smbpasswd ;			\
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd ;                  \
	fi

.include "../../mk/bsd.pkg.mk"
