# $NetBSD: Makefile,v 1.1.1.1 1999/09/15 03:22:32 jlam Exp $
#

DISTNAME=	gperiodic-1.2.6
WRKSRC=		${WRKDIR}/gperiodic
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://gperiodic.seul.org/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include	# for libintl.h
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

pre-configure:
.for file in config.cache config.h config.log config.status
	${RM} -f ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
