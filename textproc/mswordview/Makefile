# $NetBSD: Makefile,v 1.4 2000/06/09 18:41:34 drochner Exp $
#

DISTNAME=	mswordview-0.5.14
CATEGORIES=	textproc
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/mswordview/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.csn.ul.ie/~caolan/docs/MSWordView.html

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

WRKSRC=		${WRKDIR}/mswordview

USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
