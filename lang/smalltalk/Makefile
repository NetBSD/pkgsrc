# $NetBSD: Makefile,v 1.29 2004/10/15 12:03:53 tv Exp $

DISTNAME=		smalltalk-2.1.4
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=		GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
