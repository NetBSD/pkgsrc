# $NetBSD: Makefile,v 1.3 2001/08/20 02:28:26 jlam Exp $
# FreeBSD Id: ports/misc/rpm2cpio/Makefile,v 1.2 1999/08/25 07:22:29 obrien Exp

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/index.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

CONFLICTS+=	rpm-*

USE_PERL5=	# defined
REPLACE_PERL=	rpm2cpio

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .
NO_WRKSUBDIR=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
