# $NetBSD: Makefile,v 1.42 2003/08/19 09:19:37 dmcmahill Exp $
#

DISTNAME=		tgif-4.1.43
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://bourbon.usc.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_BUILDLINK2=		yes
USE_IMAKE=		yes
USE_X11=		yes

PTHREAD_OPTS+=		require

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
