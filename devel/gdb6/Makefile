# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:27 tv Exp $
#

DISTNAME=		gdb-6.1.1
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
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gdb6
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gdb6

USE_MAKEINFO=		yes
INFO_FILES=		annotate.info bfd.info configure.info
INFO_FILES+=		gdb.info gdbint.info mmalloc.info
INFO_FILES+=		stabs.info standards.info

.include "../../mk/bsd.prefs.mk"

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

do-test:
	if `${PKG_INFO} -qe dejagnu` ;then		\
		(cd ${WRKSRC} && ${GMAKE} check);	\
	else						\
		${ECHO} dejagnu is required for the test target;	\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
