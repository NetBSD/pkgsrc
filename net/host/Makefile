# $NetBSD: Makefile,v 1.2 2001/09/09 20:36:38 agc Exp $

DISTNAME=	host_991529
PKGNAME=	host-991529
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nikhef.nl/user/e07/
COMMENT=	powerful DNS query and testing tool

.include "../../mk/bsd.prefs.mk"

# If you've removed $HOSTALIASES support from your system then
# you won't have the hostalias() function in libc....
.if !defined(NO_HOSTALIASES)
MAKE_ENV+=	ALLOW_HOSTALIASES=-DALLOW_HOSTALIASES
.endif

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

# MAKE_ENV will have the right effect...
MAKEFLAGS+=	-e

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/mxlookup \
		> ${WRKDIR}/mxlookup.out
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/rblookup \
		> ${WRKDIR}/rblookup.out

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/host ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/mxlookup.out ${PREFIX}/bin/mxlookup
	${INSTALL_SCRIPT} ${WRKDIR}/rblookup.out ${PREFIX}/bin/rblookup
	${INSTALL_MAN} ${WRKDIR}/host.1 ${PREFIX}/man/man1/host.1

.include "../../mk/bsd.pkg.mk"
