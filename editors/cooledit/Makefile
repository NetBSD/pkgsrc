# $NetBSD: Makefile,v 1.2 2002/09/21 11:12:51 jlam Exp $
#

DISTNAME=	cooledit-3.17.5
CATEGORIES=	editors
MASTER_SITES=	http://cooledit.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cooledit.sourceforge.net/
COMMENT=	full-featured text editor

BUILD_USES_MSGFMT=	# defined
USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-configure:
	if ! ${GREP} -q mbstate_t /usr/include/machine/ansi.h ; then \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
