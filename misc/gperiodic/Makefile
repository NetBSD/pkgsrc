# $NetBSD: Makefile,v 1.9 2001/12/12 18:13:25 wiz Exp $
#

DISTNAME=	gperiodic-1.2.6
WRKSRC=		${WRKDIR}/gperiodic
CATEGORIES=	misc x11
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://gperiodic.seul.org/
COMMENT=	Displays a periodic table of the elements

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

USE_BUILDLINK_ONLY=	yes

pre-configure:
.for f in config.cache config.h config.log config.status
	${RM} -f ${WRKSRC}/$f
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1/

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
