# $NetBSD: Makefile,v 1.13 2004/04/25 08:53:35 snj Exp $

DISTNAME=	radiusd-cistron-1.6.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/ \
		ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.radius.cistron.nl/
COMMENT=	RADIUS-compliant remote authentication and accounting server

CONFLICTS+=	freeradius-[0-9]*

USE_BUILDLINK3=	YES
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
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/radiusd-cistron/
.for i in	ChangeLog README README.CVX README.Y2K README.cisco	\
		README.pam README.proxy README.radrelay README.simul	\
		README.tunnel README.usersfile
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/radiusd-cistron/
.endfor
.for i in	radclient.1 radlast.1 radtest.1 radwho.1 radzap.1
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man1/
.endfor
.for i in	clients.5rad naslist.5rad
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man5/
.endfor
.for i in	radiusd.8 radrelay.8 radwatch.8
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man8/
.endfor

.include "../../mk/bsd.pkg.mk"
