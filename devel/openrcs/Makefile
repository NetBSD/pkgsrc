# $NetBSD: Makefile,v 1.5 2017/09/03 08:36:52 wiz Exp $

DISTNAME=	openrcs-20110824192219
CATEGORIES=	devel
#MASTER_SITES=	http://chl.be/openrcs/

MAINTAINER=	asau@inbox.ru
#HOMEPAGE=	http://chl.be/openrcs/
COMMENT=	OpenRCS is RCS clone from OpenBSD project

WRKSRC=		${WRKDIR}/openrcs

USE_TOOLS+=	aclocal automake autoconf yacc
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize --copy --force
	cd ${WRKSRC} && ${TOOLS_CMD.aclocal}
	cd ${WRKSRC} && ${TOOLS_CMD.autoconf}
	cd ${WRKSRC} && ${TOOLS_CMD.autoheader}
	cd ${WRKSRC} && ${TOOLS_CMD.automake} --foreign --add-missing --copy

.include "../../mk/bsd.pkg.mk"
