# $NetBSD: Makefile,v 1.7 2003/10/11 14:23:04 grant Exp $

DISTNAME=	host_991529
PKGNAME=	host-991529
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nikhef.nl/user/e07/
COMMENT=	Powerful DNS query and testing tool

CONFLICTS+=	bind-[0-9]*

.include "../../mk/bsd.prefs.mk"

# If you've removed $HOSTALIASES support from your system then
# you won't have the hostalias() function in libc....
.if !defined(NO_HOSTALIASES)
MAKE_ENV+=	ALLOW_HOSTALIASES=-DALLOW_HOSTALIASES
.endif

NO_CONFIGURE=	yes

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
