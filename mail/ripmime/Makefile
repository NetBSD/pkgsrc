# $NetBSD: Makefile,v 1.12 2013/08/30 16:53:45 joerg Exp $
#

DISTNAME=	ripmime-1.4.0.10
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.pldaniels.com/ripmime/
COMMENT=	Extract the attached files out of a MIME encoded email package

MAKE_JOBS_SAFE=		no
MAKE_ENV+=	LIBS=${BUILDLINK_LDADD.iconv}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=tautological-compare
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
