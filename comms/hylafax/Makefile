# $NetBSD: Makefile,v 1.81 2024/02/11 23:56:28 gdt Exp $

# This package has a complicated upstream situation.  One upstream is
# "hylafax.org"; the last release was 6.0.7 on 2018-09-18.  Another
# upstream is https://sourceforge.net/projects/hylafax/; the last
# release is 7.0.7 on 2023-01-23.  Neither is the original hylafax.
# Probably, this package should switch to the sourceforge upstream.

DISTNAME=	hylafax-6.0.7
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/
# https://sourceforge.net/projects/hylafax/files/hylafax/hylafax-7.0.7.tar.gz/download

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hylafax.org/
# nnnnnnnnhttps://sourceforge.net/projects/hylafax/
COMMENT=	Telecommunication and fax server system
LICENSE=	sgi-free-software-b-v2.0

CONFLICTS=	hylafax-devel-[0-9]* mgetty-[0-9]*
DEPENDS+=	mawk>=1.2.2:../../lang/mawk

# http://bugs.hylafax.org/show_bug.cgi?id=1004
#BROKEN=	requires tiff2ps which is no longer part of tiff

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

# Relocations result in a linker error
MKPIE_SUPPORTED=	no

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
