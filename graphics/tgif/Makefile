# $NetBSD: Makefile,v 1.33 2001/08/22 17:38:58 jlam Exp $
#

DISTNAME=		tgif-4.1.40
PKGNAME=		tgif-4.1.40nb3
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.cs.umd.edu/pub/tgif/ \
			ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_IMAKE=		yes
USE_X11=		yes

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
