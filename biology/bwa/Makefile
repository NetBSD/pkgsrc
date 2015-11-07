# $NetBSD: Makefile,v 1.2 2015/11/07 20:20:54 dholland Exp $
#

DISTNAME=	bwa-0.7.9a
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bio-bwa/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://bio-bwa.sourceforge.net/
COMMENT=	Map low-divergent sequences against a large reference genome
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl:run gmake
REPLACE_PERL=	*.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# unconditionally uses <emmintrin.h>
ONLY_FOR_PLATFORM=	*-*-x86_64 *-*-i386 *-*-ia64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
