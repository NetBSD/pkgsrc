# $NetBSD: Makefile,v 1.22 2003/06/18 09:22:23 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vicsrc-2.8
PKGNAME=	${DISTNAME:S/src//}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	mbone tk
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/
COMMENT=	MBONE video conferencing tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

.include "../../mk/bsd.pkg.mk"
