# $NetBSD: Makefile,v 1.1 2003/02/27 08:51:00 darcy Exp $

DISTNAME=	freeradius-0.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --with-logdir=/var/log
USE_BUILDLINK2= YES
USE_LIBTOOL= YES

RADDB=		acct_users attrs clients clients.conf dictionary \
		dictionary.acc dictionary.aptis dictionary.ascend \
		dictionary.bay dictionary.cisco dictionary.compat \
		dictionary.erx dictionary.foundry dictionary.freeradius \
		dictionary.livingston dictionary.microsoft dictionary.nomadix \
		dictionary.quintum dictionary.redback dictionary.shasta \
		dictionary.shiva dictionary.tunnel dictionary.usr \
		dictionary.versanet hints huntgroups ldap.attrmap naslist \
		naspasswd postgresql.conf proxy.conf radiusd.conf realms \
		snmp.conf sql.conf users x99.conf

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/etc/raddb
.for db in ${RADDB}
	${INSTALL_DATA} ${WRKSRC}/raddb/${db} ${PREFIX}/etc/raddb/${db}.sample
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/radiusd ${PREFIX}/etc/rc.d/radiusd

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
