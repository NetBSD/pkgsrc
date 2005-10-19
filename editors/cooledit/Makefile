# $NetBSD: Makefile,v 1.19 2005/10/19 10:53:43 adam Exp $

DISTNAME=	cooledit-3.17.17
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/editors/X/cooledit/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cooledit.sourceforge.net/
COMMENT=	Full-featured text editor

BUILD_USES_MSGFMT=	yes

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-configure:
	if ${GREP} -q mbstate_t /usr/include/machine/ansi.h ; then :; else \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
