# $NetBSD: Makefile,v 1.21 2000/09/01 17:58:04 jwise Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/27 23:01:53 cwt Exp
#

DISTNAME=	scotty-2.1.8
CATEGORIES=	net tk80
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

BROKEN=		This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib/tcl8.0 \
		--with-tk-config=${PREFIX}/lib/tk8.0
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

post-extract:
	@${RM} -f ${WRKSRC}/../doc/http.n

pre-install:
	@cd ${WRKSRC};${MAKE} sinstall
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc

.include "../../mk/bsd.pkg.mk"
