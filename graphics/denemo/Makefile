# $NetBSD: Makefile,v 1.47 2014/05/05 00:47:55 ryoon Exp $
#

DISTNAME=	denemo-0.9.2
PKGREVISION=	17
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_GNU:=denemo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.denemo.org/
COMMENT=	GUI musical score editor written in C/GTK+
LICENSE=	gnu-gpl-v3

DEPENDS+=	lilypond-[0-9]*:../../print/lilypond

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config gmake

EXTRACT_USING=	bsdtar

INSTALLATION_DIRS=	etc/${PKGBASE}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/denemo.conf ${PKG_SYSCONFDIR}/denemo/denemo.conf

#XXX Makefile contains .destdir/ path
post-install:
	${RM} ${DESTDIR}${PREFIX}/share/denemo/actions/Makefile*
	${RM} ${DESTDIR}${PREFIX}/share/denemo/examples/Makefile*
	${RM} ${DESTDIR}${PREFIX}/share/denemo/manual/images/Makefile*
	${RM} ${DESTDIR}${PREFIX}/share/denemo/templates/Makefile*

.include "../../audio/aubio/buildlink3.mk"
.include "../../audio/libsmf/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
