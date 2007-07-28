# $NetBSD: Makefile,v 1.33.4.1 2007/07/28 22:57:12 ghen Exp $
#

DISTNAME=	gdb-5.3
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	Symbolic debugger for multiple language frontends

BROKEN_IN=	pkgsrc-2005Q4 pkgsrc-2006Q1 pkgsrc-2006Q4

NOT_FOR_PLATFORM=	Darwin-*-*

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=		install install-info
TEST_TARGET=		check
INFO_FILES=		# PLIST.common
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
