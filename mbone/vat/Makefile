# $NetBSD: Makefile,v 1.32 2000/09/01 17:58:05 jwise Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

BROKEN=			This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www-nrg.ee.lbl.gov/vat/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		tk-8.0.5:../../x11/tk80
DEPENDS+=		gsm-1.0.10:../../audio/gsm

NOT_FOR_PLATFORM=	*-*-alpha	# filter.cc compiler error

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/gsm

INSTALL_TARGET=		install install-man

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
