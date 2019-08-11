# $NetBSD: Makefile,v 1.21 2019/08/11 13:23:03 wiz Exp $
#

DISTNAME=	boxbackup-0.11.1
PKGNAME=	boxbackup-server-0.11.1
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=boxbackup/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.boxbackup.org/
COMMENT=	Backup tool

PATCHDIR=	${.CURDIR}/../../sysutils/boxbackup-client/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/boxbackup-client/distinfo

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	perl:run gmake

REPLACE_PERL+=	bin/bbstored/bbstored-certs bin/bbstored/bbstored-config
REPLACE_PERL+=	lib/raidfile/raidfile-config

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=  -lexecinfo
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/parcels/boxbackup*-backup-server-*/bbstoreaccounts ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/parcels/boxbackup*-backup-server-*/bbstored ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/parcels/boxbackup*-backup-server-*/bbstored-certs ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/parcels/boxbackup*-backup-server-*/bbstored-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/parcels/boxbackup*-backup-server-*/raidfile-config ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
