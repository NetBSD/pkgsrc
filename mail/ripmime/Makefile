# $NetBSD: Makefile,v 1.11 2013/08/01 20:19:55 shattered Exp $
#

DISTNAME=	ripmime-1.4.0.10
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

MAKE_JOBS_SAFE=		no
MAKE_ENV+=	LIBS=${BUILDLINK_LDADD.iconv}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
