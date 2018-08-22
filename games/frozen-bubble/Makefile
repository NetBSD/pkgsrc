# $NetBSD: Makefile,v 1.61 2018/08/22 09:45:09 wiz Exp $

DISTNAME=	frozen-bubble-2.2.1-beta1
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-SDL>=2.1.2:../../devel/p5-SDL
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=	p5-Compress-Bzip2-[0-9]*:../../archivers/p5-Compress-Bzip2
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple
DEPENDS+=	p5-Locale-Maketext-Lexicon-[0-9]*:../../misc/p5-Locale-Maketext-Lexicon

USE_TOOLS+=	gmake perl pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

MAKE_ENV+=	CP=${CP:Q} GMAKE=${GMAKE:Q} PERL5=${PERL5:Q} INSTALLDIRS="vendor"
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} \
    INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q} \
    INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q} \
    INSTALL_LIB=${INSTALL_LIB:Q} \
    INSTALL_MAN=${INSTALL_MAN:Q} \
    INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Games/FrozenBubble/.packlist

.include "../../audio/SDL_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_Pango=	SDL_Pango>=0.1.2nb8
.include "../../devel/SDL_Pango/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
