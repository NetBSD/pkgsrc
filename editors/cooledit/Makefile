# $NetBSD: Makefile,v 1.26 2006/12/06 14:45:42 joerg Exp $

DISTNAME=	cooledit-3.17.17
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/editors/X/cooledit/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://cooledit.sourceforge.net/
COMMENT=	Full-featured text editor

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

post-configure:
	if ${GREP} -q mbstate_t /usr/include/wchar.h ; then :; else \
		${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.bak ; \
		${SED} 's;^.*HAVE_WCHAR_H.*$$;/* mbstate_t is missing from machine/ansi.h */;g' \
			< ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h ; \
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
