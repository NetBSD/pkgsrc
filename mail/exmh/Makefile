# $NetBSD: Makefile,v 1.36 2005/01/22 15:45:59 minskim Exp $
# FreeBSD Id: Makefile,v 1.25 1998/02/15 05:36:54 peter Exp
#

DISTNAME=	exmh-2.6.3
CATEGORIES=	mail tk
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/exmh/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.beedub.com/exmh/
COMMENT=	X11/TK based mail reader front end to MH

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	nmh>=1.0:../../mail/nmh
DEPENDS+=	metamail>=2.7:../../mail/metamail

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${PKGNAME}
USE_X11=	yes

WISH=		wish
TCLSH=		tclsh

# Additionally, exmh will use the following packages if present:
# lang/expect
# textproc/glimpse
# security/gnupg
# security/pgp
# mail/faces
# audio/rplay

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${FILESDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${FILESDIR}/install

.include "../../mk/bsd.pkg.mk"
