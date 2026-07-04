# $NetBSD: Makefile,v 1.20 2026/07/04 07:28:53 tsutsui Exp $

CANNA_MODULE=	canuum
PKGREVISION=	1

.include "../../inputmethod/canna/Makefile.common"

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

CONFIGURE_DIRS=		${WRKSRC}/canuum

INSTALL_MAKE_FLAGS+=	INSTUGIDFLAGS=

# XXX
# canuum determines whether to use TERMCAP or TERMINFO by configure script,
# but Imakefile cannot use library names checked by the configure because
# the ${CONFIGURE_CMD} is invoked via Makefile generated from Imakefile.
# Force canuum's imake-side terminal library choice to match pkgsrc's
# curses framework so that proper TERMCAP_LIB is used here.
.include "../../mk/curses.buildlink3.mk"
IMAKEOPTS+=	-DTermcapLibrary=-l${BUILDLINK_LIBNAME.curses}

.include "../../inputmethod/canna-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
