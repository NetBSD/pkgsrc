# $NetBSD: Makefile,v 1.8 2003/05/01 18:35:46 jmmv Exp $

DISTNAME=	radiusd-cistron-1.6.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/ \
		ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.radius.cistron.nl/
COMMENT=	RADIUS-compliant remote authentication and accouting server

CONFLICTS+=	freeradius*

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

MAKEFILE=	Makefile.BSD
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}/src

RCD_SCRIPTS=	radiusd

OWN_DIRS_PERMS=	/var/log/radacct ${ROOT_USER} ${ROOT_GROUP} 700

PKG_SYSCONFSUBDIR=	raddb
EGDIR=		${PREFIX}/share/examples/raddb
CONF_FILES=
.for cfile in	clients.sample dictionary dictionary.ascend dictionary.bay \
		dictionary.cisco dictionary.cistron dictionary.compat \
		dictionary.erx dictionary.livingston dictionary.redback \
		dictionary.shiva dictionary.tunnel dictionary.usr \
		dictionary.versanet hints.sample huntgroups.sample \
		naslist.sample naspasswd.sample realms.sample users.sample
CONF_FILES+=	${EGDIR}/${cfile} ${PKG_SYSCONFDIR}/${cfile:S/.sample//}
.endfor
.undef cfile

post-install:
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

.include "../../mk/bsd.pkg.mk"
