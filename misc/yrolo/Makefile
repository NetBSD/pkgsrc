# $NetBSD: Makefile,v 1.2 2002/09/24 00:26:56 jlam Exp $
#

DISTNAME=       yrolo-1.1
CATEGORIES=	misc
MASTER_SITES=   http://www.muquit.com/muquit/software/yrolo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muquit.com/muquit/software/yrolo/yrolo.html
COMMENT=	Contact management software

WRKSRC=		${WRKDIR}/yrolo1.1

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_IMAKE=	yes

INSTALL_TARGET=	install install.man

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
