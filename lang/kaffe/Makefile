# $NetBSD: Makefile,v 1.50 2003/09/23 20:56:00 dmcmahill Exp $

DISTNAME=		kaffe-1.1.0
CATEGORIES=		lang java
MASTER_SITES=		ftp://ftp.kaffe.org/pub/kaffe/v1.1.x-development/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.kaffe.org/
COMMENT=		Virtual machine capable of running Java(tm) code

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
TEST_TARGET=		check

ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-arm32 *-*-i386 *-*-m68k *-*-mips*	\
			*-*-sparc *-*-powerpc

GNU_CONFIGURE=		yes
CPPFLAGS+=		-Dunix

JVM_HOME=		${LOCALBASE}/java/kaffe
NO_MTREE=		yes	# since we change PREFIX below

OWN_DIRS=	${PREFIX}
OWN_DIRS+=	${PREFIX}/etc
OWN_DIRS+=	${PREFIX}/jre
OWN_DIRS+=	${PREFIX}/jre/lib
OWN_DIRS+=	${PREFIX}/jre/lib/security
SUPPORT_FILES=	${PREFIX}/jre/lib/security/java.security.default	\
		${PREFIX}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
#
# We need to explicitly link libkaffe*.so with libc.so so that libc symbols
# are resolved correctly when libkaffe*.so are dynamically loaded.
#
CONFIGURE_ENV+=		VM_LIBS="-lc"
.endif

.if (${OPSYS} == "NetBSD") && (${MACHINE_ARCH} == "alpha")
# On these systems, jit3 is not working.
CONFIGURE_ARGS+=	--with-engine=intrp
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
