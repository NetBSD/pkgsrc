# $NetBSD: Makefile,v 1.16 1999/03/08 10:53:57 agc Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/27 23:01:53 cwt Exp
#

DISTNAME=	scotty-2.1.8
CATEGORIES=	net tk80
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/

DEPENDS+=	tk-8.0p2:../../x11/tk80

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
