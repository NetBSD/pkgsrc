# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:04 rillig Exp $
#

DISTNAME=		gdb-6.2.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gdb/gdb.html
COMMENT=		The GNU Project Debugger

NOT_FOR_PLATFORM=	Darwin-*-*

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		autoconf213 gmake
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gdb6
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gdb6
CONFIGURE_ARGS+=	--enable-libada

USE_MAKEINFO=		yes
INFO_FILES=		annotate.info bfd.info configure.info
INFO_FILES+=		gdb.info gdbint.info mmalloc.info
INFO_FILES+=		stabs.info standards.info

.include "../../mk/bsd.prefs.mk"

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

pre-configure:
	cd ${WRKSRC}/gdb; autoheader; autoconf

do-test:
	if ${PKG_INFO} -qe dejagnu; then		\
		(cd ${WRKSRC} && ${GMAKE} check);	\
	else						\
		${ECHO} "dejagnu is required for the test target";	\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
