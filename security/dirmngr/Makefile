# $NetBSD: Makefile,v 1.36 2010/09/01 16:40:53 drochner Exp $
#

DISTNAME=		dirmngr-1.1.0
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/dirmngr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2/
COMMENT=		X509 certificate and CRL downloader

DIRMNGR_USER?=		dirmngr
DIRMNGR_GROUP?=		dirmngr
PKG_GROUPS=		${DIRMNGR_GROUP}
PKG_USERS=		${DIRMNGR_USER}:${DIRMNGR_GROUP}
PKG_GROUPS_VARS+=	DIRMNGR_GROUP
PKG_USERS_VARS+=	DIRMNGR_USER

BUILD_DEFS+=		VARBASE

PKG_HOME.${DIRMNGR_USER}=	${VARBASE}/dirmngr

GNU_CONFIGURE=		yes
USE_TOOLS+=		gawk
#USE_TOOLS+=		gmake
USE_TOOLS+=		autoconf
USE_TOOLS+=		automake
USE_TOOLS+=		gettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
RCD_SCRIPTS=		dirmngr
INFO_FILES=		YES

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/libdata
CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap-client=${BUILDLINK_PREFIX.openldap-client}

FILES_SUBST+=		VARBASE=${VARBASE:Q}
FILES_SUBST+=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		SYSCONFDIR=${SYSCONFDIR:Q}
FILES_SUBST+=		DIRMNGR_USER=${DIRMNGR_USER:Q}
FILES_SUBST+=		DIRMNGR_GROUP=${DIRMNGR_GROUP:Q}
FILES_SUBST+=		DIRMNGR_PATH=${DIRMNGR_PATH:Q}

OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr
OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr/trusted-certs
OWN_DIRS+=		${VARBASE}/cache/dirmngr

DIRMNGR_PERMS=		${DIRMNGR_USER} ${DIRMNGR_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/cache/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr/extra-certs ${DIRMNGR_PERMS}

INSTALLATION_DIRS=	sbin
PKG_DESTDIR_SUPPORT=	user-destdir

pre-build:
	${CP} ${FILESDIR}/runDirmngr.c ${WRKDIR}/runDirmngr.c

post-build:
	cd ${WRKDIR} && \
	${SETENV} ${BUILDENV} ${CC} ${CFLAGS} -DDIRMNGR_USER='"${DIRMNGR_USER}"' -DDIRMNGR_PATH='"${PREFIX}/bin/dirmngr"' -o runDirmngr runDirmngr.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/runDirmngr ${DESTDIR}${PREFIX}/sbin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
# previous pth versions have a bug which breaks CRL fetch on NetBSD
BUILDLINK_ABI_DEPENDS.pth+= pth>=2.0.7nb1
.include "../../devel/pth/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
