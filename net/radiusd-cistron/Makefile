# $NetBSD: Makefile,v 1.34 2019/08/11 13:22:29 wiz Exp $

DISTNAME=	radiusd-cistron-1.6.8
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/radius/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radius.cistron.nl/
COMMENT=	RADIUS-compliant remote authentication and accounting server

CONFLICTS+=	freeradius-[0-9]*

USE_TOOLS+=	perl:run

REPLACE_PERL=	src/checkrad.pl

MAKE_FILE=	Makefile.BSD
BUILD_DIRS=	src
INSTALL_DIRS=	src
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 sbin share/examples/raddb \
			share/doc/radiusd-cistron

RCD_SCRIPTS=	radiusd

OWN_DIRS_PERMS=	/var/log/radacct ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/radiusd-cistron/
.for i in	ChangeLog README README.CVX README.Y2K README.cisco	\
		README.pam README.proxy README.radrelay README.simul	\
		README.tunnel README.usersfile
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/radiusd-cistron/
.endfor
.for i in	radclient.1 radlast.1 radtest.1 radwho.1 radzap.1
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for i in	clients.5rad naslist.5rad
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
.endfor
.for i in	radiusd.8 radrelay.8 radwatch.8
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
.endfor

.include "../../mk/bsd.pkg.mk"
