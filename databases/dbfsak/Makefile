# $NetBSD: Makefile,v 1.3 2016/03/12 21:53:39 tnn Exp $

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
MAKE_FLAGS+=	CPP=${CC:Q}
MAKE_FLAGS+=	CFLAGS="${CFLAGS} -I. -DVERSION='\"${PKGVERSION_NOREV}\"'"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbfsak ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dbfsak.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
