# $NetBSD: Makefile,v 1.16 1999/12/27 11:08:15 tron Exp $
# FreeBSD Id: Makefile,v 1.13 1998/01/03 10:58:40 obrien Exp
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	minicom-1.82.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/serialcomm/dialout/} \
		http://www.pp.clinet.fi/~walker/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.clinet.fi/~walker/minicom.html

BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	kermit-*:../../comms/kermit
DEPENDS+=	lrzsz-*:../../comms/lrzsz

USE_GMAKE=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}/src

# for BATCH !
.include "../../mk/bsd.prefs.mk"

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

post-install:
	@${CHOWN} -R uucp:dialer ${PREFIX}/etc/minicom

.include "../../mk/bsd.pkg.mk"
