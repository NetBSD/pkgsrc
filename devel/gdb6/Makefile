# $NetBSD: Makefile,v 1.2 2004/06/03 18:48:48 shannonjr Exp $
#

DISTNAME=		gdb-6.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gdb/gdb.html
COMMENT=		The GNU Project Debugger

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
GDB_SUBPREFIX=		gdb6
GDB_PREFIX=		${PREFIX}/${GDB_SUBPREFIX}
CONFIGURE_ARGS+=	--libdir=${GDB_PREFIX}/lib
CONFIGURE_ARGS+=	--includedir=${GDB_PREFIX}/include

USE_MAKEINFO=		yes
INFO_FILES=		annotate.info bfd.info configure.info
INFO_FILES+=		gdb.info gdbint.info mmalloc.info
INFO_FILES+=		stabs.info standards.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=	USE_GCC_34
USE_GCC_34?=	NO

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

do-test:
	if `${PKG_INFO} -qe dejagnu` ;then		\
		(cd ${WRKSRC} && ${GMAKE} check);	\
	else						\
		${ECHO} dejagnu is required for the test target;	\
	fi

.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.include "../../lang/gcc-3.4/buildlink3.mk"
pre-configure:
.  include "../../lang/gcc-3.4/preconfigure.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
