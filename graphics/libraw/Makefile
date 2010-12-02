# $NetBSD: Makefile,v 1.3 2010/12/02 15:35:56 wiz Exp $
#

DISTNAME=		LibRaw-0.11.3
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		graphics
MASTER_SITES=	http://www.libraw.org/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libraw.org/
COMMENT=	Raw decoding/processing library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-P ${PREFIX}

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		post-configure
SUBST_MESSAGE.pc=	Fixing prefix and version in raw.pc file.
SUBST_FILES.pc=		raw.pc
SUBST_SED.pc=		-e 's,@@PREFIX@@,${PREFIX},'
SUBST_SED.pc+=		-e 's,@@VERSION@@,${PKGVERSION_NOREV},'

INSTALLATION_DIRS+= lib/pkgconfig

pre-configure:
	${CP} ${FILESDIR}/raw.pc ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/raw.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
