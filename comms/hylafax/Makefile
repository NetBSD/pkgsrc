# $NetBSD: Makefile,v 1.42 2005/01/27 16:22:37 adam Exp $

DISTNAME=	hylafax-4.2.1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/ \
		ftp://ftp.leo.org/pub/comp/os/unix/networking/fax/hylafax/source/

MAINTAINER=	hallmanns@surfeu.de
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system

DEPENDS+=	mawk>=1.2.2:../../lang/mawk

DIST_SUBDIR=	hylafax

CONFLICTS=	mgetty-[0-9]*

USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-MAKE=${MAKE_PROGRAM}
CONFIGURE_ARGS+=	--with-INSTALL="" --nointeractive
CONFIGURE_ARGS+=	--with-ZLIBINC=-I${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-LIBZ="-L${BUILDLINK_PREFIX.zlib}/lib -lz"
CONFIGURE_ENV+=		PREFIX="${PREFIX}" OPTIMIZER="${CFLAGS}"
CONFIGURE_ENV+=		FAXUID="${FAXUSER}" FAXGID="${FAXGROUP}"
MANCOMPRESSED=		yes

FAXUSER?=	uucp
FAXGROUP?=	dialer
RCD_SCRIPTS=	hylafax

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
