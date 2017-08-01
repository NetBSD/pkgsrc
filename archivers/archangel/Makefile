# $NetBSD: Makefile,v 1.14 2017/08/01 16:47:35 wiz Exp $

DISTNAME=	archangel-20050730
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Compressing archiver which can sign and encrypt entries

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/archangel

USE_FEATURES=	nbcompat
MAKE_ENV+=	LDADD=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aatar ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aatar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
