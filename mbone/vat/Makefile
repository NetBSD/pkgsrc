# $NetBSD: Makefile,v 1.48 2005/04/05 10:35:13 wiz Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

MAINTAINER=		mycroft@NetBSD.org
HOMEPAGE=		http://www-nrg.ee.lbl.gov/vat/
COMMENT=		The Visual Audio Tool - multicast audioconferencing

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX} --with-tk=${PREFIX}

CPPFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/gsm

INSTALL_TARGET=		install install-man

.include "../../audio/gsm/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
