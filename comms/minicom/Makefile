# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:21 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1998/01/03 10:58:40 obrien Exp
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	minicom-1.78
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/software/

MAINTAINER=     packages@netbsd.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz \
		kermit:${PORTSDIR}/comms/kermit

WRKSRC=		${WRKDIR}/${PKGNAME}/src
IS_INTERACTIVE=	yes

MAN1=		minicom.1 runscript.1 ascii-xfr.1

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include "../../mk/bsd.pkg.mk"
