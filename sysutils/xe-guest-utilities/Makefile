# $NetBSD: Makefile,v 1.10 2015/04/20 08:05:30 sborrill Exp $
#

# Values from XenServer 6.5.0 = 6, 5, 0, 90977
# Values from XenServer 6.0.2 = 6, 0, 2, 52898
# Values from XenServer 6.0 = 6, 0, 0, 50560
# Values from XenServer 5.6 SP2 = 5, 6, 100, 39153
XENMAJOR=	6
XENMINOR=	5
XENTEENY=	0
XENBUILD=	90977

VERSION=	${XENMAJOR}.${XENMINOR}.${XENTEENY}
DISTNAME=	xe-guest-utilities_5.6.0-595
CATEGORIES=	sysutils
PKGNAME=	xe-guest-utilities-${VERSION}
MASTER_SITES=	http://updates.vmd.citrix.com/XenServer/5.6.0/debian/pool/main/x/xe-guest-utilities/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://www.xenserver.com/
COMMENT=	NetBSD VM tools for Citrix XenServer
LICENSE=	gnu-gpl-v2

DEPENDS+=	xenstoretools-[0-9]*:../../sysutils/xenstoretools

ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[0-9]+$$//:C/_/-/}

SRCFILES=	xe-daemon xe-update-guest-attrs

NO_CONFIGURE=	yes
NO_BUILD=	yes

RCD_SCRIPTS=		xenguest
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	${SRCFILES}
SUBST_SED.paths=	-e "s,@VARBASE@,${VARBASE},g"
SUBST_SED.paths+=	-e "s,@PREFIX@,${PREFIX},g"

SUBST_CLASSES+=		version
SUBST_STAGE.version=	post-patch
SUBST_FILES.version=	xe-update-guest-attrs
SUBST_SED.version=	-e "s,@XENMAJOR@,${XENMAJOR},g"
SUBST_SED.version+=	-e "s,@XENMINOR@,${XENMINOR},g"
SUBST_SED.version+=	-e "s,@XENTEENY@,${XENTEENY},g"
SUBST_SED.version+=	-e "s,@XENBUILD@,${XENBUILD},g"

INSTALLATION_DIRS=	sbin

do-install:
	for file in ${SRCFILES}; do				\
		${INSTALL_SCRIPT} ${WRKSRC}/$${file} ${DESTDIR}${PREFIX}/sbin/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
