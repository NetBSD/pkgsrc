# $NetBSD: Makefile,v 1.7 2001/01/09 17:50:03 abs Exp $
#

DISTNAME=		rc5-mlg-004
PKGNAME=		rc5des-0.4
CATEGORIES=		security
MASTER_SITES=		http://www.flame.org/netbsd-rc5/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.distributed.net/rc5/

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386

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

do-install:
	${MKDIR} ${PREFIX}/RC5
	cd ${WRKSRC}; ${PAX} -r -w . ${PREFIX}/RC5

.include "../../mk/bsd.pkg.mk"
