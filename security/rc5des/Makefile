# $NetBSD: Makefile,v 1.1.1.1 1998/11/24 16:52:18 agc Exp $
#

DISTNAME=		rc5-mlg-004
PKGNAME=		rc5des-0.4
CATEGORIES=		security
MASTER_SITES=		http://www.flame.org/netbsd-rc5/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://rc5.distributed.net/

ONLY_FOR_ARCHS=		alpha arm32 i386

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

WRKSRC=			${WRKDIR}/RC5

NO_CONFIGURE=		yes

# agc - this is commented out until I can test that it works.
#post-patch:
#	@(hostname=`/bin/hostname`;					\
#	fqdn=`/usr/sbin/host $$hostname | ${AWK} '{ print $$1; exit }'`; \
#	${MV} ${WRKSRC}/master.ini ${WRKSRC}/master.ini.in;		\
#	${SED} -e 's|your\.site|'$$fqdn'|g' ${WRKSRC}/master.ini.in > ${WRKSRC}/master.ini)

do-build:
	cd ${WRKSRC}; rm -f master.ini.orig rc5.sh.orig

# agc - commented out until the above is tested.
#do-build:
#	cd ${WRKSRC}; rm -f master.ini.orig master.ini.in rc5.sh.orig

do-install:
	${MKDIR} ${PREFIX}/RC5
	cd ${WRKSRC}; /bin/pax -r -w . ${PREFIX}/RC5

.include "../../mk/bsd.pkg.mk"
