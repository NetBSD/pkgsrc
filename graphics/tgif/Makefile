# $NetBSD: Makefile,v 1.28 2000/11/10 23:43:48 dmcmahill Exp $
#

DISTNAME=		tgif-4.1.40
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.cs.umd.edu/pub/tgif/ \
			ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html

DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		yes

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../mk/bsd.pkg.mk"
