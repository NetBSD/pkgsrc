# $NetBSD: Makefile,v 1.30 2001/06/30 11:47:00 zuntum Exp $
#

DISTNAME=		tgif-4.1.40
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.cs.umd.edu/pub/tgif/ \
			ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_BUILDLINK_ONLY=	yes
USE_IMAKE=		yes

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
