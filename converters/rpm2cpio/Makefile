# $NetBSD: Makefile,v 1.16 2004/06/03 23:07:29 heinz Exp $
# FreeBSD Id: ports/misc/rpm2cpio/Makefile,v 1.2 1999/08/25 07:22:29 obrien Exp

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.iagora.com/~espel/index.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	YES

DIST_SUBDIR=	${PKGNAME}
REPLACE_PERL=	rpm2cpio

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
NO_BUILD=	YES

# conflicts with rpm package, which also contains a rpm2cpio
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin/rpm2cpio.pl

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
