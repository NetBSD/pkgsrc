# $NetBSD: Makefile,v 1.18 2026/07/02 16:59:20 tsutsui Exp $

CANNA_MODULE=	canuum

.include "../../inputmethod/canna/Makefile.common"

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

CONFIGURE_DIRS=		${WRKSRC}/canuum

INSTALL_MAKE_FLAGS+=	INSTUGIDFLAGS=

.include "../../mk/curses.buildlink3.mk"
SUBST_CLASSES+=		fix_curs
SUBST_STAGE.fix_curs=	pre-configure
SUBST_MESSAGE.fix_curs=	Fixing curses
SUBST_FILES.fix_curs+=	canuum/Imakefile
SUBST_SED.fix_curs+=	-e 's/TERMCAP_LIB = .*/TERMCAP_LIB = -l'${BUILDLINK_LIBNAME.curses}'/g'

.include "../../inputmethod/canna-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
