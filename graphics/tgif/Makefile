# $NetBSD: Makefile,v 1.44 2004/04/24 01:01:54 wiz Exp $
#

DISTNAME=		tgif-4.1.43
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://bourbon.usc.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_BUILDLINK3=		yes
USE_IMAKE=		yes
USE_X11=		yes

PTHREAD_OPTS+=		require

# avoid "xmkmf -a" on Solaris which runs makedepend because the
# openwindows makedepend program can't handle the number of
# files.  We should probably have a replacement makedepend in
# pkgsrc.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
XMKMF=			${XMKMF_CMD}
.endif

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP} ${WRKSRC}/Tgif.tmpl-${LOWER_OPSYS} ${WRKSRC}/Tgif.tmpl

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
