# $NetBSD: Makefile,v 1.72 2015/12/29 00:05:54 dholland Exp $

DISTNAME=	hylafax-6.0.6
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system
LICENSE=	sgi-free-software-b-v2.0

CONFLICTS=	hylafax-devel-[0-9]* mgetty-[0-9]*
DEPENDS+=	mawk>=1.2.2:../../lang/mawk

BUILD_DEFS+=	FAXUSER FAXGROUP VARBASE

USE_LANGUAGES=		c c++
USE_TOOLS+=		gs:run pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-MAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ARGS+=	--with-INSTALL="" --nointeractive
CONFIGURE_ARGS+=	--with-ZLIBINC=-I${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-LIBZ="-L${BUILDLINK_PREFIX.zlib}/lib -lz"
CONFIGURE_ARGS+=	--with-SYSVINIT=no
CONFIGURE_ARGS+=	--with-DIR_MAN=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ENV+=		FAXUID=${FAXUSER:Q}
CONFIGURE_ENV+=		FAXGID=${FAXGROUP:Q}
CONFIGURE_ENV+=		OPTIMIZER=${CFLAGS:Q}
CONFIGURE_ENV+=		VARBASE=${VARBASE}
CHECK_PORTABILITY_SKIP=	rpm/jobcontrol.sh
MANCOMPRESSED=		yes

FAXUSER?=	uucp
FAXGROUP?=	dialer
RCD_SCRIPTS=	hfaxd faxq

EGDIR=		share/examples/hylafax

INSTALLATION_DIRS=	libdata/hylafax ${EGDIR} ${EGDIR}/templates

SPECIAL_PERMS+=	bin/faxalter ${SETUID_ROOT_PERMS} \
		bin/faxrm ${SETUID_ROOT_PERMS} \
		libexec/faxgetty ${SETUID_ROOT_PERMS} \
		sbin/faxq ${SETUID_ROOT_PERMS}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
CONFIGURE_ENV+=		MACHDEPLIBS=-lrt
.endif

# Affected by TIFFHeader -> TIFFHeaderClassic change in 4.x.
BUILDLINK_API_DEPENDS.libtiff+=	tiff>=4.0.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
