# $NetBSD: Makefile,v 1.11 2001/02/17 17:37:24 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/07/17 19:29:07 andreas Exp
#

DISTNAME=       glimpse-4.1.src
PKGNAME=	glimpse-4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	textproc databases
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://glimpse.cs.arizona.edu/
COMMENT=	Text search engine

RESTRICTED=	"Restrictive copyright (don't sell for profit)"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-configure:
	${CHMOD} ugo+x ${WRKSRC}/configure

post-configure:
	${CP} -f ${FILESDIR}/autoconf.h \
		 ${WRKSRC}/libtemplate/include/autoconf.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
