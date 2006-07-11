# $NetBSD: Makefile,v 1.52 2006/07/11 12:12:41 dmcmahill Exp $
#

DISTNAME=		tgif-4.1.45
CATEGORIES=		graphics
MASTER_SITES=		ftp://bourbon.usc.edu/pub/tgif/free-of-charge/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://bourbon.usc.edu:8001/tgif/tgif.html
COMMENT=		Fully-featured X11 drawing program

USE_IMAKE=		yes

PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
OS_TEMPLATE=	${WRKSRC}/Tgif.tmpl-freebsd
.else
OS_TEMPLATE=	${WRKSRC}/Tgif.tmpl-${LOWER_OPSYS}
.endif

post-patch::
	@${RM} -f ${WRKSRC}/Tgif.tmpl
	@${CP}  ${OS_TEMPLATE} ${WRKSRC}/Tgif.tmpl

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
