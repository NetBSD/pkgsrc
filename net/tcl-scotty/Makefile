# $NetBSD: Makefile,v 1.8 2003/11/20 14:26:00 he Exp $
#

DISTNAME=	scotty-${DIST_VERS}
PKGNAME=	tcl-scotty-${DIST_VERS}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://wwwhome.cs.utwente.nl/~schoenw/scotty/
COMMENT=	Network management extensions to TCL

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

DIST_VERS=	2.1.11

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib --enable-multicast \
		--enable-gdmo --without-tk-config
CONFIGURE_ENV+=	TARGET=scotty

USE_LIBTOOL=	yes

post-extract:
	@${RM} -f ${WRKSRC}/../doc/http.n
	@${RM} -f ${WRKSRC}/../doc/tkined.1

do-install:
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} tnm-install install-man sinstall

post-install:
	cd ${PREFIX}/bin && ${LN} -f -s scotty${DIST_VERS} scotty

.include "../../mk/bsd.pkg.mk"
