# $NetBSD: Makefile,v 1.10 2002/04/12 15:17:22 mrauch Exp $
#

DISTNAME=		rc5-mlg-004
PKGNAME=		rc5des-0.4
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.flame.org/netbsd-rc5/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.distributed.net/rc5/
COMMENT=		Binaries for taking part in the rc5des challenge

# This package requires emulators/compat12,compat13 and compat14
# but only if we aren't running the relevant release natively.
.include "../../mk/bsd.prefs.mk"
RELEASE!= ${ECHO} ${OS_VERSION} | ${AWK} -F. '{print $$1*100+$$2}'
.if ${RELEASE}>104
DEPENDS+=		compat14-[0-9]*:../../emulators/compat14
.if ${RELEASE}>103
DEPENDS+=		compat13-[0-9]*:../../emulators/compat13
.if ${RELEASE}>102
DEPENDS+=		compat12-[0-9]*:../../emulators/compat12
.endif
.endif
.endif

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
	${INSTALL_DATA_DIR} ${PREFIX}/RC5
	cd ${WRKSRC}; ${PAX} -r -w . ${PREFIX}/RC5

.include "../../mk/bsd.pkg.mk"
