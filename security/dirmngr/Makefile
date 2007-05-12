# $NetBSD: Makefile,v 1.28 2007/05/12 11:19:18 shannonjr Exp $
#

DISTNAME=		dirmngr-1.0.0
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/dirmngr/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		pth-2.0.7.tar.gz
SITES.pth-2.0.7.tar.gz=	${MASTER_SITE_GNU:=pth/}
DISTFILES+=		libassuan-1.0.1.tar.bz2
SITES.libassuan-1.0.1.tar.bz2=	ftp://ftp.gnupg.org/gcrypt/libassuan/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2/
COMMENT=		X509 certificate and CRL downloader

DIRMNGR_USER?=		dirmngr
DIRMNGR_GROUP?=		dirmngr
PKG_GROUPS=		${DIRMNGR_GROUP}
PKG_USERS=		${DIRMNGR_USER}:${DIRMNGR_GROUP}

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
CONFIGURE_ENV+=		BUILDLINK_PREFIX_openldap-client=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-pth-prefix=${WRKDIR}/pth
CONFIGURE_ARGS+=	--with-libassuan-prefix=${WRKDIR}/libassuan

SUBST_FILES+=		VARBASE=${VARBASE}
SUBST_FILES+=		PREFIX=${PREFIX}
SUBST_FILES+=		SYSCONFDIR=${SYSCONFDIR}
SUBST_FILES+=		DIRMNGR_USER=${DIRMNGR_USER}
SUBST_FILES+=		DIRMNGR_PATH=${DIRMNGR_PATH:Q}

OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr
OWN_DIRS+=		${PKG_SYSCONFDIR}/dirmngr/trusted-certs

DIRMNGR_PERMS=		${DIRMNGR_USER} ${DIRMNGR_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${VARBASE}/dirmngr/cache ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr ${DIRMNGR_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/libdata/dirmngr/extra-certs ${DIRMNGR_PERMS}

# We are building a static pth library and linking against it
# We are also building libassuan here to get libassuan-pth.
pre-configure:
	cd  ${WRKDIR}/pth-2.0.7 && ./configure --prefix=${WRKDIR}/pth --enable-pthread --enable-static --disable-shared && ${MAKE} install
	cd  ${WRKDIR}/libassuan-1.0.1 && \
	${SETENV} ${CONFIGURE_ENV} ./autogen.sh && \
	${SETENV} ${CONFIGURE_ENV} ./configure --enable-maintainer-mode --prefix=${WRKDIR}/libassuan --with-pth-prefix=${WRKDIR}/pth && \
	${SETENV} ${PKGSRC_MAKE_ENV} ${MAKE} install
	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

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
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
