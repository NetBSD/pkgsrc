# $NetBSD: Makefile,v 1.13 2000/09/01 17:58:05 jwise Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

BROKEN=		This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=	tk-8.0.5:../../x11/tk80

GNU_CONFIGURE=	yes
USE_X11=	yes

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
