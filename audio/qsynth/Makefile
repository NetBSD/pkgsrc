# $NetBSD: Makefile,v 1.3 2006/01/24 07:31:55 wiz Exp $

DISTNAME=	qsynth-0.2.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qsynth/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qsynth.sourceforge.net/
COMMENT=	Qt GUI Interface to FluidSynth

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	src/*.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qsynth ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/icons/qsynth.png ${PREFIX}/share/icons/

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
