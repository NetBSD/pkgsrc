# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:38 tv Exp $
#

DISTNAME=	cooledit-3.17.5
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://cooledit.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cooledit.sourceforge.net/
COMMENT=	Full-featured text editor

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		# defined
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-configure:
	if ${GREP} -q mbstate_t /usr/include/machine/ansi.h ; then :; else \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
