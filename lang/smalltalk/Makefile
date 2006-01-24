# $NetBSD: Makefile,v 1.34 2006/01/24 07:32:19 wiz Exp $

DISTNAME=	smalltalk-2.1.9
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

LIBTOOLIZE_PLIST=	NO # Manually created libc.la breaks PLIST.
USE_TOOLS+=		gawk gmake
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}/lib
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--without-emacs
#CONFIGURE_ARGS+=	--without-glib --without-gtk
#CONFIGURE_ENV+=		CFLAGS="-O2 -fsigned-char"

INFO_FILES=		gst-base.info gst-libs.info gst.info
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
