# $NetBSD: Makefile,v 1.5 2003/07/30 12:08:47 jmmv Exp $

DISTNAME=	freeradius-0.7
CATEGORIES=	net
PKGREVISION=	2
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.Awfulhak.org/pub/radius/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

CONFLICTS+=	radiusd-cistron*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2= YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS=		--quiet
CONFIGURE_ARGS+=	--with-logdir=/var/log
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include

.include "../../mk/bsd.prefs.mk"

# Needs semaphore functions as well as thread libs.
.if ${OPSYS} == "NetBSD"
.  if ${OS_VERSION:M1.[0-5]*} || ${OS_VERSION} == "1.6" || ${OS_VERSION:M1.6[A-M]*} || ${OS_VERSION:M1.6.1*}
CONFIGURE_ARGS+=	--with-threads=no
.  endif
.endif

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
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" ${FILESDIR}/radiusd \
		> ${PREFIX}/etc/rc.d/radiusd

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
