# $NetBSD: Makefile,v 1.39 2003/05/02 11:55:31 wiz Exp $
#

DISTNAME=		tgif-4.1.42
PKGREVISION=	2
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@netbsd.org
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
