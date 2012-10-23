# $NetBSD: Makefile,v 1.21 2012/10/23 18:16:56 asau Exp $
#

DISTNAME=		rc5-mlg-004
PKGNAME=		rc5des-0.4
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.flame.org/netbsd-rc5/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.distributed.net/rc5/
COMMENT=		Binaries for taking part in the rc5des challenge

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386
EMUL_MODULES.netbsd=	base

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "netbsd-i386"
EMUL_REQD=		netbsd>=1.2
.else
EMUL_REQD=		netbsd>=1.3
.endif

CRYPTO=			yes
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/RC5

# agc - this is commented out until I can test that it works.
#post-patch:
#	@(hostname=`/bin/hostname`;					\
#	fqdn=`/usr/sbin/host $$hostname | ${AWK} '{ print $$1; exit }'`; \
#	${MV} ${WRKSRC}/master.ini ${WRKSRC}/master.ini.in;		\
#	${SED} -e 's|your\.site|'$$fqdn'|g' ${WRKSRC}/master.ini.in > ${WRKSRC}/master.ini)

do-build:
	cd ${WRKSRC}; ${RM} -f master.ini.orig rc5.sh.orig

# agc - commented out until the above is tested.
#do-build:
#	cd ${WRKSRC}; ${RM} -f master.ini.orig master.ini.in rc5.sh.orig

INSTALLATION_DIRS+=	RC5

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/RC5

.include "../../mk/bsd.pkg.mk"
