# $NetBSD: Makefile,v 1.3 2001/12/20 10:05:49 martti Exp $

DISTNAME=	radiusd-cistron-1.6.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/ \
		ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.radius.cistron.nl/
COMMENT=	RADIUS-compliant remote authentication and accouting server

MAKEFILE=	Makefile.BSD

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} install
	@${MKDIR} -m 700 /var/log/radacct
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.CVX ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.Y2K ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.cisco ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.pam ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.proxy ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.radrelay ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.simul ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.tunnel ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_DATA} ${WRKSRC}/doc/README.usersfile ${PREFIX}/share/doc/radiusd-cistron
	${INSTALL_MAN} ${WRKSRC}/doc/radclient.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radlast.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radtest.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/raduse.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radwho.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/radzap.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/clients.5rad ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/naslist.5rad ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/radiusd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/radrelay.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/radwatch.8 ${PREFIX}/man/man8

post-install:
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" ${FILESDIR}/radiusd.sh.tmpl \
		> ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHMOD} 555 ${PREFIX}/etc/rc.d/radiusd.sh
	@${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/etc/rc.d/radiusd.sh

.include "../../mk/bsd.pkg.mk"
