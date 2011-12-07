# $NetBSD: Makefile,v 1.12 2011/12/07 16:07:14 roy Exp $

PKGREVISION=	3
CANNA_MODULE=	canuum

.include "../../inputmethod/canna/Makefile.common"

MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

CONFIGURE_DIRS=	. canuum
BUILD_DIRS=	canuum

INSTALL_MAKE_FLAGS+=	INSTUGIDFLAGS=

SPECIAL_PERMS+=	bin/canuum ${SETUID_ROOT_PERMS}

.include "../../mk/curses.buildlink3.mk"
SUBST_CLASSES+=		fix_curs
SUBST_STAGE.fix_curs=	post-patch
SUBST_MESSAGE.fix_curs=	Fixing curses
SUBST_FILES.fix_curs+=	canuum/Imakefile
SUBST_SED.fix_curs+=	-e 's/TERMCAP_LIB = .*/TERMCAP_LIB = -l'${BUILDLINK_LIBNAME.curses}'/g'

.include "../../inputmethod/canna-lib/buildlink3.mk"

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/canuum
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/cannaconf.h ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/canna/ccompat.h ${WRKSRC}/canuum

.include "../../mk/bsd.pkg.mk"
