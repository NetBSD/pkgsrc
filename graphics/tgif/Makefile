# $NetBSD: Makefile,v 1.49 2005/08/23 02:33:32 dmcmahill Exp $
#

DISTNAME=		tgif-4.1.44
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://bourbon.usc.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_IMAKE=		yes

PTHREAD_OPTS+=		require

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-${LOWER_OPSYS} ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# avoid "xmkmf -a" on Solaris which runs makedepend because the
# openwindows makedepend program can't handle the number of
# files.  We should probably have a replacement makedepend in
# pkgsrc.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
XMKMF=			${XMKMF_CMD}
.endif
