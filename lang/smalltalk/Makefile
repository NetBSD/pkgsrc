# $NetBSD: Makefile,v 1.13 2003/03/10 07:43:57 jmc Exp $
#

DISTNAME=	smalltalk-1.95.10
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

USE_GMAKE=		YES
USE_GNU_READLINE=	YES
USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--without-libiconv
CONFIGURE_ARGS+=	--without-glib --without-gtk
CONFIGURE_ENV+=		CFLAGS="-O2 -fsigned-char"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
