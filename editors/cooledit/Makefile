# $NetBSD: Makefile,v 1.1.1.1 2002/07/07 19:45:39 dmcmahill Exp $
#

DISTNAME=	cooledit-3.17.5
CATEGORIES=	editors
MASTER_SITES=	http://cooledit.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cooledit.sourceforge.net/
COMMENT=	full-featured text editor

USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=	yes

post-configure:
	if ! ${GREP} -q mbstate_t /usr/include/machine/ansi.h ; then \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
