# $NetBSD: Makefile,v 1.12 1999/02/20 22:48:31 hubertf Exp $
#

DISTNAME=		tgif-4.0.9
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.cs.umd.edu/pub/tgif/ \
			ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=		mcmahill@alum.mit.edu
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html

USE_IMAKE=		yes

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../mk/bsd.pkg.mk"
