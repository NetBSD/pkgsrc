# $NetBSD: Makefile,v 1.39 2001/05/05 19:51:17 jlam Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www-nrg.ee.lbl.gov/vat/
COMMENT=		The Visual Audio Tool - multicast audioconferencing

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
DEPENDS+=		tk>=8.3.2:../../x11/tk
DEPENDS+=		gsm-1.0.10:../../audio/gsm

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

CPPFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/gsm

INSTALL_TARGET=		install install-man

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
