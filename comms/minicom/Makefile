# $NetBSD: Makefile,v 1.9 1998/08/20 15:16:42 tsarna Exp $
# FreeBSD Id: Makefile,v 1.13 1998/01/03 10:58:40 obrien Exp
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	minicom-1.78
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/software/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://www.clinet.fi/~walker/minicom.html

RUN_DEPENDS=	lrz:../../comms/lrzsz \
		lsz:../../comms/lrzsz \
		kermit:../../comms/kermit

WRKSRC=		${WRKDIR}/${PKGNAME}/src
IS_INTERACTIVE=	yes

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include "../../mk/bsd.pkg.mk"
