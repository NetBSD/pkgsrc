# $NetBSD: Makefile,v 1.13 2014/05/05 00:47:47 ryoon Exp $

CONFLICTS+=	emacs23-nox11-[0-9]*

.include "../../editors/emacs23/Makefile.common"
PKGREVISION=	24

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

# Replace manual page which only includes another one with a symbolic link
# if manual compression is activated. The manual page won't work otherwise.
.if defined(MANZ)
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ctags.1
	${LN} -s etags.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ctags.1
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
