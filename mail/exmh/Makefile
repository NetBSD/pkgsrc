# $NetBSD: Makefile,v 1.22 2000/03/07 20:18:42 kim Exp $
# FreeBSD Id: Makefile,v 1.25 1998/02/15 05:36:54 peter Exp
#

DISTNAME=	exmh-2.1.1
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/exmh/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.beedub.com/exmh/

DEPENDS+=	tcl-8.0.5:../../lang/tcl80
DEPENDS+=	tk-8.0.5:../../x11/tk80
DEPENDS+=	nmh>=1.0:../../mail/nmh
DEPENDS+=	mm>=2.7:../../mail/metamail

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${PKGNAME}
USE_X11=	yes

WISH=		wish8.0
TCLSH=		tclsh8.0

# Additionally, exmh will use the following packages if present:
# lang/expect
# textproc/glimpse
# security/pgp
# mail/faces
# audio/rplay

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include "../../mk/bsd.pkg.mk"
