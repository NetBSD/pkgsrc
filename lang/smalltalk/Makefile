# $NetBSD: Makefile,v 1.23 2004/01/24 13:51:15 grant Exp $

DISTNAME=		smalltalk-2.1.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=		GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INFO_FILES=		gst-base.info gst-libs.info gst.info

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}/lib
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--without-glib --without-gtk
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ENV+=		CFLAGS="-O2 -fsigned-char"

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
