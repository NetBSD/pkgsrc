# $NetBSD: Makefile,v 1.23 2000/05/12 06:20:49 rh Exp $
#

DISTNAME=		tgif-4.1.33
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.cs.umd.edu/pub/tgif/ \
			ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://bourbon.cs.umd.edu:8001/tgif/tgif.html

USE_IMAKE=		yes

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-netbsd ${WRKSRC}/Tgif.tmpl

.include "../../mk/bsd.pkg.mk"
