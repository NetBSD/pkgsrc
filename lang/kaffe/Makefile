# $NetBSD: Makefile,v 1.38 2002/06/23 05:13:10 jlam Exp $
#

DISTNAME=		kaffe-1.0.6
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.kaffe.org/
COMMENT=		Virtual machine capable of running Java(tm) code

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-mips* *-*-sparc

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/kaffe
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
		${PREFIX}/kaffe/share

test:
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} check

.include "../../devel/gmp/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"

.include "../../mk/bsd.pkg.mk"
