# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 18:01:22 rh Exp $
#

DISTNAME=	nsca-1.1.0
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://netsaint.sourceforge.net/docs/0_0_6/addons.html\#nsca
COMMENT=	submit passive NetSaint checks results to another server

DEPENDS+=	netsaint-base-*:../../net/netsaint-base

GNU_CONFIGURE=	YES

do-install:
.for prg in nsca send_nsca
	${INSTALL_PROGRAM} ${WRKSRC}/src/${prg} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${prg}.cfg ${PREFIX}/etc/${prg}.cfg.sample
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nsca
.for doc in Changelog README SECURITY
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/nsca
.endfor

.include "../../mk/bsd.pkg.mk"
