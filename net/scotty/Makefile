# $NetBSD: Makefile,v 1.14 1998/09/18 17:45:08 agc Exp $
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
PLIST_SRC=	${WRKDIR}/PLIST-src

post-extract:
	@${RM} -f ${WRKSRC}/../doc/http.n

pre-install:
	@cd ${WRKSRC};make sinstall
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc
	@${SED} "s,@NETBSD_VERSION@,$$(uname -m)-$$(uname)-$$(uname -r)," ${PKGDIR}/PLIST >${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
