# $NetBSD: Makefile,v 1.56 2016/03/05 11:29:19 jperkin Exp $

DISTNAME=	dirmngr-1.1.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/dirmngr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/aegypten2/
COMMENT=	X509 certificate and CRL downloader
LICENSE=	gnu-gpl-v3

CONFLICTS=	gnupg2-2.1.[0-9]*

DIRMNGR_USER?=		dirmngr
DIRMNGR_GROUP?=		dirmngr
PKG_GROUPS=		${DIRMNGR_GROUP}
PKG_USERS=		${DIRMNGR_USER}:${DIRMNGR_GROUP}
PKG_GROUPS_VARS+=	DIRMNGR_GROUP
PKG_USERS_VARS+=	DIRMNGR_USER

BUILD_DEFS+=		VARBASE

PKG_HOME.${DIRMNGR_USER}=	${VARBASE}/dirmngr

USE_TOOLS+=		autoconf automake gawk gettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
RCD_SCRIPTS=		dirmngr
INFO_FILES=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/libdata
CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap-client=${BUILDLINK_PREFIX.openldap-client}

FILES_SUBST+=		VARBASE=${VARBASE}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		SYSCONFDIR=${SYSCONFDIR}
FILES_SUBST+=		DIRMNGR_USER=${DIRMNGR_USER}
FILES_SUBST+=		DIRMNGR_GROUP=${DIRMNGR_GROUP}
FILES_SUBST+=		DIRMNGR_PATH=${DIRMNGR_PATH:Q}

OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr
OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr/trusted-certs
OWN_DIRS+=		${VARBASE}/cache/dirmngr

DIRMNGR_PERMS=		${DIRMNGR_USER} ${DIRMNGR_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/cache/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr/extra-certs ${DIRMNGR_PERMS}

INSTALLATION_DIRS=	sbin

post-build:
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -DDIRMNGR_USER='"${DIRMNGR_USER}"' -DDIRMNGR_PATH='"${PREFIX}/bin/dirmngr"' -o ${WRKDIR}/runDirmngr ${FILESDIR}/runDirmngr.c

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
