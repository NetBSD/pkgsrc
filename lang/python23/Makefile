# $NetBSD: Makefile,v 1.11 2003/12/08 21:13:56 recht Exp $
#

DISTNAME=	Python-2.3.2
PKGNAME=	python23-2.3.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.3.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_DB185=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT="${CFLAGS}"
UNLIMIT_RESOURCES+=	stacksize

INSTALL_TARGET=	altinstall
TEST_TARGET=	test

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS=   sunos
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "IRIX"
PY_PLATNAME=${LOWER_OPSYS}
.else
PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME}

# the dl module isn't built for 64 bit archs and Darwin
.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "amd64" \
	|| ${MACHINE_ARCH} == "sparc64" || ${MACHINE_ARCH} == "x86_64" \
	|| ${OPSYS} == "Darwin"
PLIST_SUBST+=  DLMODULE="@comment "
.else
PLIST_SUBST+=  DLMODULE=
.endif

X86_SUBST=		"@comment "
OSSAUDIODEV_SUBST=	"@comment "
.if ${MACHINE_ARCH} == "i386"
# activate X86_ONLY modules
X86_SUBST=
# ossaudiodev is only available on x86 for the following platforms
.if ${PY_PLATNAME} == "linux2" || ${PY_PLATNAME} == "freebsd4" \
	|| ${PY_PLATNAME} == "freebsd5"
OSSAUDIODEV_SUBST=
.endif
.endif
PLIST_SUBST+=  X86_ONLY=${X86_SUBST}
PLIST_SUBST+=  OSSAUDIODEV=${OSSAUDIODEV_SUBST}

# ensure that the bsddb185 module is build on all platforms
.include "../../databases/db/buildlink2.mk"

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	"Fixing paths for db 1.85."
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,%%DB185_H%%,${DB185_H},g'
SUBST_SED.setup+=	-e 's,%%DB185_INCS%%,${DB185_INCS},g'
SUBST_SED.setup+=	-e 's,%%DB185_LIBS%%,${DB185_LIBS},g'
SUBST_SED.setup+=	-e 's,%%DB185_LIBDIR%%,${DB185_LIBDIR},g'

DB185_LIBDIR=		${BUILDLINK_PREFIX.db}/lib

.if !empty(BUILDLINK_CPPFLAGS.db)
LDFLAGS+=	${BUILDLINK_LDFLAGS.db}
DBINCDIR=	${BUILDLINK_CPPFLAGS.db:S/-I//}
DB185_INCS=	${DBINCDIR}
DB185_LIBS=	${BUILDLINK_LIBS.db:S/-l//}

.if ${_NEED_DB2} == "YES"
DB185_H=	${DBINCDIR}/db_185.h
.else
DB185_H=	${DBINCDIR}/db.h
.endif
.else
DB185_H=	/usr/include/db.h
DB185_INCS=	/usr/include
DB185_LIBS=
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
