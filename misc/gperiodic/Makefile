# $NetBSD: Makefile,v 1.8 2001/04/02 18:46:07 wiz Exp $
#

DISTNAME=	gperiodic-1.2.6
WRKSRC=		${WRKDIR}/gperiodic
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://gperiodic.seul.org/
COMMENT=	Displays a periodic table of the elements

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

pre-configure:
.for f in config.cache config.h config.log config.status
	${RM} -f ${WRKSRC}/$f
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
