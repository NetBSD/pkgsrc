# $NetBSD: Makefile,v 1.22 2008/01/23 05:38:46 tnn Exp $
#

DISTNAME=		gdb-6.2.1
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gdb/gdb.html
COMMENT=		The GNU Project Debugger

NOT_FOR_PLATFORM=	Darwin-*-*

USE_TOOLS+=		gmake makeinfo msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gdb6
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gdb6
CONFIGURE_ARGS+=	--enable-libada
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

do-test:
	if ${PKG_INFO} -qe dejagnu; then		\
		(cd ${WRKSRC} && ${GMAKE} check);	\
	else						\
		${ECHO} "dejagnu is required for the test target";	\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
