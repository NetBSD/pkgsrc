# $NetBSD: Makefile,v 1.10 2005/05/02 22:33:37 shannonjr Exp $
#

DISTNAME=		dirmngr-0.9.1
#PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/dirmngr/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.4.tar.gz
SITES_pth-2.0.4.tar.gz=	${MASTER_SITE_GNU:=pth/}

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2
COMMENT=		X509 certificate and CRL downloader

DIRMNGR_USER?=		dirmngr
DIRMNGR_GROUP?=		dirmngr
PKG_GROUPS=		${DIRMNGR_GROUP}
PKG_USERS=		${DIRMNGR_USER}:${DIRMNGR_GROUP}::pseudo\\ user:${VARBASE}/dirmngr:

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		awk
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
RCD_SCRIPTS=		dirmngr
PKG_RCD_SCRIPTS=	yes

CONFIGURE_ARGS+=	--localstatedir="${VARBASE}"
CONFIGURE_ARGS+=	--sharedstatedir="${VARBASE}"
CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth

SUBST_FILES+=		VARBASE=${VARBASE}
SUBST_FILES+=		PREFIX=${PREFIX}
SUBST_FILES+=		SYSCONFDIR=${SYSCONFDIR}
SUBST_FILES+=		DIRMNGR_USER=${DIRMNGR_USER}
SUBST_FILES+=		DIRMNGR_PATH=${DIRMNGR_PATH}

# We are building a static pth library and linking against it
pre-configure:
	cd  ${WRKDIR}/pth-2.0.4 && ./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && ${MAKE} install

pre-build:
	${CP} ${FILESDIR}/runDirmngr.c ${WRKDIR}/runDirmngr.c

post-build:
	cd ${WRKDIR} && \
	${SETENV} ${BUILDENV} ${CC} ${CFLAGS} -DDIRMNGR_USER='"${DIRMNGR_USER}"' -DDIRMNGR_PATH='"${PREFIX}/bin/dirmngr"' -o runDirmngr runDirmngr.c

pre-install:
	${INSTALL_DATA_DIR} ${VARBASE}/dirmngr/cache
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/dirmngr
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/dirmngr/trusted-certs
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/dirmngr/extra-certs
	${CHOWN} -R ${DIRMNGR_USER}:${DIRMNGR_GROUP} ${VARBASE}/dirmngr
	${CHOWN} -R ${DIRMNGR_USER}:${DIRMNGR_GROUP} ${PREFIX}/libdata/dirmngr

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/runDirmngr ${PREFIX}/sbin

INFO_FILES=		dirmngr.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
