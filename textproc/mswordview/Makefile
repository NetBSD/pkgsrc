# $NetBSD: Makefile,v 1.3 1999/07/09 18:50:02 thorpej Exp $
#

DISTNAME=	mswordview-0.5.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/mswordview/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.csn.ul.ie/~caolan/docs/MSWordView.html

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

WRKSRC=		${WRKDIR}/mswordview

USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
