# $NetBSD: Makefile,v 1.40 2002/09/08 09:03:37 zuntum Exp $
#

DISTNAME=		kaffe-1.0.7
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/v1.0.x-production/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kaffe.org/
COMMENT=		Virtual machine capable of running Java(tm) code

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc *-*-powerpc

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/java/kaffe
CONFIGURE_ARGS+=	--with-includes=""
CONFIGURE_ARGS+=	--with-libraries=""
CPPFLAGS+=		-Dunix

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
#
# We need to explicitly link libkaffe*.so with libc.so so that libc symbols
# are resolved correctly when libkaffe*.so are dynamically loaded.
#
CONFIGURE_ENV+=		VM_LIBS="-lc"
.endif


post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms \
		${PREFIX}/java/kaffe/share

test:
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} check

.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
