# $NetBSD: Makefile,v 1.1.1.1 2005/07/14 21:45:29 agc Exp $

DISTNAME=	archangel-20050714
CATEGORIES=	archivers
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/agc/software.html
COMMENT=	Compressing archiver which can sign and encrypt entries

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg

GNU_CONFIGURE+=	yes
WRKSRC=		${WRKDIR}/archangel

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
