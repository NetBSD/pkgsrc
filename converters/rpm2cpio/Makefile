# $NetBSD: Makefile,v 1.8 2001/11/28 05:20:43 jlam Exp $
# FreeBSD Id: ports/misc/rpm2cpio/Makefile,v 1.2 1999/08/25 07:22:29 obrien Exp

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.0nb1
CATEGORIES=	misc
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/index.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

USE_BUILDLINK_ONLY=	YES

DIST_SUBDIR=	${PKGNAME}
REPLACE_PERL=	rpm2cpio

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
WRKSRC=		${WRKDIR}
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin/rpm2cpio.pl

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
