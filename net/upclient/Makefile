# $NetBSD: Makefile,v 1.7 2001/01/29 11:34:38 wiz Exp $
#

DISTNAME=	upclient-4.09
CATEGORIES=	net
MASTER_SITES=	http://www.atomicvoid.net/uptimes/ \
		http://www.uptimes.net/download/ \
		ftp://ftp.uptimes.net/pub/uptimes/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.uptimes.net/

ALL_TARGET=	upclient

.if !defined(UPCLIENT_LOGIN) || \
    !defined(UPCLIENT_PASSWORD) || \
    !defined(UPCLIENT_HOSTID)
IS_INTERACTIVE=	yes
.endif

post-patch:
	${MV} ${WRKSRC}/upchk ${WRKSRC}/upchk.bak
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		>${WRKSRC}/upchk <${WRKSRC}/upchk.bak

do-configure:
	@${ECHO} "" ; \
	${ECHO} '******************************************************' ;\
	if [ "${UPCLIENT_LOGIN}" = "" -o \
	     "${UPCLIENT_PASSWORD}" = "" -o \
	     "${UPCLIENT_HOSTID}" = "" ]; then \
		${ECHO} "" ; \
		${ECHO} 'See http://www.uptimes.net/ for more information!' ; \
		${ECHO} "" ; \
	fi ; \
	if [ "${UPCLIENT_LOGIN}" = "" ]; then \
		${ECHO} -n "Upclient login: " ; \
		read UPCLIENT_LOGIN ;  \
	else \
		UPCLIENT_LOGIN=${UPCLIENT_LOGIN} ; \
	fi ; \
	if [ "${UPCLIENT_PASSWORD}" = "" ]; then \
		${ECHO} -n "Upclient password: " ; \
		read UPCLIENT_PASSWORD ;  \
	else \
		UPCLIENT_PASSWORD=${UPCLIENT_PASSWORD} ; \
	fi ; \
	if [ "${UPCLIENT_HOSTID}" = "" ]; then \
		${ECHO} -n "Upclient host-id: " ; \
		read UPCLIENT_HOSTID ;  \
	else \
		UPCLIENT_HOSTID=${UPCLIENT_HOSTID} ; \
	fi ; \
	${ECHO} "" ; \
	${ECHO} Configuring with: ; \
	${ECHO} UPCLIENT_LOGIN=$$UPCLIENT_LOGIN  ; \
	${ECHO} UPCLIENT_PASSWORD=$$UPCLIENT_PASSWORD ; \
	${ECHO} UPCLIENT_HOSTID=$$UPCLIENT_HOSTID ; \
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.BAK ; \
	${SED} \
		-e "s/@UPCLIENT_LOGIN@/$$UPCLIENT_LOGIN/" \
		-e "s/@UPCLIENT_PASSWORD@/$$UPCLIENT_PASSWORD/" \
		-e "s/@UPCLIENT_HOSTID@/$$UPCLIENT_HOSTID/" \
		<${WRKSRC}/config.h.BAK >${WRKSRC}/config.h ; \
	${ECHO} "" ; \
	${ECHO} '******************************************************' ;\
	${ECHO} ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/upclient ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/upclient
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@INSTALL@|${INSTALL}|g' \
		-e 's|@SU@|${SU}|g' \
		${FILESDIR}/upclient.sh >${PREFIX}/etc/rc.d/upclient
	${CHMOD} +x ${PREFIX}/etc/rc.d/upclient

pre-package:
	@${ECHO} '********************************************************' ;\
	 ${ECHO} "* Please remember that the upclient binary package has" ; \
	 ${ECHO} "* your login, password and hostid compiled in. Make sure" ; \
	 ${ECHO} "* you know what you're doing with the binary pkg!" ; \
	 ${ECHO} '********************************************************' ;\

.include "../../mk/bsd.pkg.mk"
