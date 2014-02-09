# $NetBSD: Makefile,v 1.1 2014/02/09 09:24:22 obache Exp $

DISTNAME=	frink-2.2.2p4
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Frink/
COMMENT=	Frink is a tcl formatting and static syntax check program
LICENSE=	frink-license

RESTRICTED=	For commercial use please contact the author.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INSTALLATION_DIRS=	bin share/doc/frink

WRKSRC=		${WRKDIR}/frink-2.2.2
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/frink
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/frink

.include "../../mk/bsd.pkg.mk"
