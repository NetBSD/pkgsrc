# $NetBSD: Makefile,v 1.43 2003/06/18 09:22:21 agc Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www-nrg.ee.lbl.gov/vat/
COMMENT=		The Visual Audio Tool - multicast audioconferencing

DEPENDS+=		tk>=8.3.2:../../x11/tk
DEPENDS+=		gsm-1.0.10:../../audio/gsm

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

CPPFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/gsm

INSTALL_TARGET=		install install-man

.include "../../mk/bsd.pkg.mk"
