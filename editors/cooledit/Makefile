# $NetBSD: Makefile,v 1.41 2026/10/20 20:57:33 ktnb Exp $

DISTNAME=	cooledit-5.0.6
CATEGORIES=	editors
MASTER_SITES=	https://www.ibiblio.org/pub/Linux/apps/editors/X/cooledit/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paulsheer/cooledit
COMMENT=	Full-featured text editor
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${PKGBASE}

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

CHECK_RELRO_SKIP+=	bin/remotefs

post-configure:
	if ${GREP} -q mbstate_t /usr/include/wchar.h ; then :; else \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
