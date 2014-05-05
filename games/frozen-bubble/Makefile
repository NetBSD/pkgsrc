# $NetBSD: Makefile,v 1.48 2014/05/05 00:47:51 ryoon Exp $
#

DISTNAME=	frozen-bubble-2.2.0
PKGREVISION=	14
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-SDL>=2.1.2:../../devel/p5-SDL
DEPENDS+=	p5-gettext>=0:../../devel/p5-gettext

USE_TOOLS+=	gmake perl pkg-config

REPLACE_PERL+=	frozen-bubble frozen-bubble-editor

MAKE_ENV+=	CP=${CP:Q} GMAKE=${GMAKE:Q} PERL5=${PERL5:Q} INSTALLDIRS="vendor"
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} \
    INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q} \
    INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q} \
    INSTALL_LIB=${INSTALL_LIB:Q} \
    INSTALL_MAN=${INSTALL_MAN:Q} \
    INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

PERL5_PACKLIST=	auto/fb_c_stuff/.packlist

.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_Pango=	SDL_Pango>=0.1.2nb8
.include "../../devel/SDL_Pango/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
