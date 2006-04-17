# $NetBSD: Makefile,v 1.41 2006/04/17 13:46:38 wiz Exp $

DISTNAME=	smalltalk-2.1.9
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

USE_TOOLS+=		gawk gmake makeinfo pkg-config
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

IGNORE_LIBTOOLIZE=	lib/smalltalk/libc.la
INFO_FILES=		# PLIST
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
