# $NetBSD: Makefile,v 1.1 2019/08/30 17:33:25 micha Exp $

DISTNAME=	chocolate-doom-3.0.0
CATEGORIES=	games
MASTER_SITES=	http://www.chocolate-doom.org/downloads/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chocolate-doom.org/
COMMENT=	Doom/Heretic/Hexen/Strife source port
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../mk/bsd.prefs.mk"

# no inb/outb
.if ${OPSYS} == NetBSD
CONFIGURE_ENV+=	ac_cv_lib_i386_i386_iopl=no
CONFIGURE_ENV+=	ac_cv_lib_amd64_amd64_iopl=no
.endif

PYTHON_FOR_BUILD_ONLY=		yes
CONFIGURE_ENV+=			ac_cv_prog_HAVE_PYTHON=python${PYVERSSUFFIX}
REPLACE_PYTHON+=		data/convert-icon
REPLACE_PYTHON+=		man/docgen
REPLACE_PYTHON+=		man/simplecpp

.include "../../lang/python/application.mk"

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
