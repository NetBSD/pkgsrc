# $NetBSD: Makefile,v 1.9 2004/04/25 08:32:36 snj Exp $
#

DISTNAME=	nsca-1.1.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://netsaint.sourceforge.net/docs/0_0_6/addons.html\#nsca
COMMENT=	Submit passive NetSaint checks results to another server

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

EGDIR=		${PREFIX}/share/examples/nsca

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
.for prg in nsca send_nsca
	${INSTALL_PROGRAM} ${WRKSRC}/src/${prg} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${prg}.cfg ${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nsca
.for doc in Changelog README SECURITY
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/nsca
.endfor

.include "../../mk/bsd.pkg.mk"
