# $NetBSD: Makefile,v 1.31 2013/02/01 22:21:05 wiz Exp $
#

DISTNAME=		gdb-6.2.1
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gdb/gdb.html
COMMENT=		The GNU Project Debugger

NOT_FOR_PLATFORM=	Darwin-*-* DragonFly-*-*

USE_TOOLS+=		gmake makeinfo msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR=gdb6
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gdb6
CONFIGURE_ARGS+=	--enable-libada
INFO_FILES=		yes

.include "options.mk"

pre-patch:
	${CP} ${FILESDIR}/nbsd-nat.c ${WRKSRC}/gdb

do-test:
	if ${PKG_INFO} -qe dejagnu; then		\
		(cd ${WRKSRC} && ${GMAKE} check);	\
	else						\
		${ECHO} "dejagnu is required for the test target";	\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
