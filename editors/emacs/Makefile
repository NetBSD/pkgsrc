# $NetBSD: Makefile,v 1.152 2012/12/22 10:34:20 tron Exp $

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs/Makefile.common"
PKGREVISION=	10

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

# Replace manual page which only includes another one with a symbolic link
# if manual compression is activated. The manual page won't work otherwise.
.ifdef(MANZ)
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/man/man1/ctags.1
	${LN} -s etags.1 ${DESTDIR}${PREFIX}/man/man1/ctags.1
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
