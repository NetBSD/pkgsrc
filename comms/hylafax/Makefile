# $NetBSD: Makefile,v 1.66 2012/10/03 11:24:40 asau Exp $

VERS=		4.2.5
DISTNAME=	hylafax-${VERS}
PKGREVISION=	7
CATEGORIES=	comms
MASTER_SITES_BETA=	ftp://ftp.hylafax.org/source/BETA/
MASTER_SITES_RELEASE=	ftp://ftp.hylafax.org/source/
MASTER_SITES=	${MASTER_SITES_RELEASE}

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system

DEPENDS+=	mawk>=1.2.2:../../lang/mawk

CONFLICTS=	hylafax-devel-[0-9]* mgetty-[0-9]*

BUILD_DEFS+=	FAXUSER FAXGROUP VARBASE

USE_LANGUAGES=		c c++
USE_TOOLS+=		gs:run
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-MAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ARGS+=	--with-INSTALL="" --nointeractive
CONFIGURE_ARGS+=	--with-ZLIBINC=-I${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-LIBZ="-L${BUILDLINK_PREFIX.zlib}/lib -lz"
CONFIGURE_ARGS+=	--with-SYSVINIT=no
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} OPTIMIZER=${CFLAGS:Q}
CONFIGURE_ENV+=		FAXUID=${FAXUSER:Q} FAXGID=${FAXGROUP:Q}
CONFIGURE_ENV+=		VARBASE=${VARBASE:Q}
MANCOMPRESSED=		yes

FAXUSER?=	uucp
FAXGROUP?=	dialer
RCD_SCRIPTS=	hylafax

MAKE_JOBS_SAFE=	NO

INSTALLATION_DIRS=	libdata/hylafax

SPECIAL_PERMS+=	bin/faxalter ${SETUID_ROOT_PERMS} \
		bin/faxrm ${SETUID_ROOT_PERMS} \
		libexec/faxgetty ${SETUID_ROOT_PERMS} \
		sbin/faxq ${SETUID_ROOT_PERMS}

PKG_OPTIONS_VAR=	PKG_OPTIONS.hylafax
PKG_SUPPORTED_OPTIONS=	pam
#pam doesn't work right now, so disabled by default
#PKG_SUGGESTED_OPTIONS=       pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
CONFIGURE_ENV+=		MACHDEPLIBS=-lrt
.endif

# Affected by TIFFHeader -> TIFFHeaderClassic change in 4.x.
BUILDLINK_API_DEPENDS.libtiff+=	tiff>=4.0.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
