# $NetBSD: Makefile,v 1.2 1999/01/16 17:26:03 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1998/09/26 23:18:07 steve Exp
#

DISTNAME=	xldlas-0.85
WRKSRC=		${WRKDIR}/xldlas
CATEGORIES=	math
MASTER_SITES=	http://a42.com/~thor/xldlas/			\
		http://sunsite.math.klte.hu/mirrors/xldlas/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xapps/math
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://a42.com/~thor/xldlas/

DEPENDS+=	xforms-0.88:../../x11/xforms

ONLY_FOR_ARCHS=	arm32 i386 m68k sparc ns32k

USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include "../../mk/bsd.pkg.mk"
