# $NetBSD: Makefile,v 1.5 2001/01/04 17:09:55 wiz Exp $
#

DISTNAME=	gperiodic-1.2.6
WRKSRC=		${WRKDIR}/gperiodic
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://gperiodic.seul.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

pre-configure:
.for file in config.cache config.h config.log config.status
	${RM} -f ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
