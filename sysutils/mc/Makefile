# $NetBSD: Makefile,v 1.46 2004/12/20 15:58:27 wiz Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

DISTNAME=		mc-4.5.51
PKGREVISION=		5
CATEGORIES=		sysutils
MASTER_SITES+=		${MASTER_SITE_GNOME:=stable/sources/mc/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ibiblio.org/mc/
COMMENT=		Midnight Commander, a free Norton Commander Clone

BUILD_USES_MSGFMT=	YES

CONFLICTS+=		gmc-[0-9]*

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-netrc --with-included-slang
CONFIGURE_ARGS+=	--with-samba
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-tk
CONFIGURE_ARGS+=	--without-tm-x-support
CONFIGURE_ARGS+=	--without-x

# Don't pick up readline if it's installed in the build environment.
#
CONFIGURE_ENV+=		ac_cv_header_history_h=no
CONFIGURE_ENV+=		ac_cv_header_readline_h=no
CONFIGURE_ENV+=		ac_cv_header_readline_history_h=no
CONFIGURE_ENV+=		ac_cv_header_readline_readline_h=no

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

LIBS+=			-lm -ltermcap		# -lslang
CPPFLAGS+=		-Dunix

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+= -DSunOS
.endif

# Remove unwanted directories in a non-GNOME installation.
#
post-install:
	${RMDIR} -p ${PREFIX}/share/idl 2>/dev/null || ${TRUE}
	${RMDIR} -p ${PREFIX}/share/pixmaps/mc 2>/dev/null || ${TRUE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
