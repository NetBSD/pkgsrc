# $NetBSD: Makefile,v 1.19 2001/05/05 19:51:17 jlam Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/
COMMENT=	MBONE video conferencing tool

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
DEPENDS+=	tk>=8.3.2:../../x11/tk

GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
