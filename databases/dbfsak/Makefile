# $NetBSD: Makefile,v 1.2 2014/01/02 20:25:18 adam Exp $

DISTNAME=	dbfsak-4.6.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbfsak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbfsak.sourceforge.net/
COMMENT=	Tool for converting to and from DBF files
LICENSE=	artistic

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKEFLAGS+=	CPP=${CC:Q}
MAKEFLAGS+=	CFLAGS="${CFLAGS} -I. -DVERSION='\"${PKGVERSION_NOREV}\"'"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbfsak ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dbfsak.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
