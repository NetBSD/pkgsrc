# $NetBSD: Makefile,v 1.1.1.1 2000/09/07 17:38:39 jwise Exp $
#

DISTNAME=	scotty-2.1.10
PKGNAME=	tcl-scotty-2.1.10
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib --enable-multicast \
		--enable-gdmo --without-tk-config
CONFIGURE_ENV+=	TARGET=scotty

USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

post-extract:
	@${RM} -f ${WRKSRC}/../doc/http.n
	@${RM} -f ${WRKSRC}/../doc/tkined.1

do-install:
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tnm-install install-man sinstall

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s scotty2.1.10 scotty

.include "../../mk/bsd.pkg.mk"
