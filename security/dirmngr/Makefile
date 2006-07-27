# $NetBSD: Makefile,v 1.24 2006/07/27 18:48:03 jlam Exp $
#

DISTNAME=		dirmngr-0.9.3
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/dirmngr/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.4.tar.gz
SITES.pth-2.0.4.tar.gz=	${MASTER_SITE_GNU:=pth/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2
COMMENT=		X509 certificate and CRL downloader

DIRMNGR_USER?=		dirmngr
DIRMNGR_GROUP?=		dirmngr
PKG_GROUPS=		${DIRMNGR_GROUP}
PKG_USERS=		${DIRMNGR_USER}:${DIRMNGR_GROUP}

PKG_HOME.${DIRMNGR_USER}=	${VARBASE}/dirmngr

GNU_CONFIGURE=		yes
USE_TOOLS+=		gawk
USE_PKGLOCALEDIR=	yes
RCD_SCRIPTS=		dirmngr
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap-client=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth

SUBST_FILES+=		VARBASE=${VARBASE}
SUBST_FILES+=		PREFIX=${PREFIX}
SUBST_FILES+=		SYSCONFDIR=${SYSCONFDIR}
SUBST_FILES+=		DIRMNGR_USER=${DIRMNGR_USER}
SUBST_FILES+=		DIRMNGR_PATH=${DIRMNGR_PATH}

OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr
OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr/trusted-certs

DIRMNGR_PERMS=		${DIRMNGR_USER} ${DIRMNGR_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${VARBASE}/dirmngr/cache ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr/extra-certs ${DIRMNGR_PERMS}

# We are building a static pth library and linking against it
pre-configure:
	cd  ${WRKDIR}/pth-2.0.4 && ./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && ${MAKE} install

pre-build:
	${CP} ${FILESDIR}/runDirmngr.c ${WRKDIR}/runDirmngr.c

post-build:
	cd ${WRKDIR} && \
	${SETENV} ${BUILDENV} ${CC} ${CFLAGS} -DDIRMNGR_USER='"${DIRMNGR_USER}"' -DDIRMNGR_PATH='"${PREFIX}/bin/dirmngr"' -o runDirmngr runDirmngr.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/runDirmngr ${PREFIX}/sbin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
