# $NetBSD: Makefile,v 1.10 2002/10/18 12:30:45 wiz Exp $
# FreeBSD Id: ports/misc/rpm2cpio/Makefile,v 1.2 1999/08/25 07:22:29 obrien Exp

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/index.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

USE_BUILDLINK2=	YES

DIST_SUBDIR=	${PKGNAME}
REPLACE_PERL=	rpm2cpio

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
WRKSRC=		${WRKDIR}
NO_BUILD=	YES

# conflicts with rpm package, which also contains a rpm2cpio
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin/rpm2cpio.pl

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
