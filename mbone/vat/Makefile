# $NetBSD: Makefile,v 1.64 2013/06/06 12:54:45 wiz Exp $
#

DISTNAME=		vatsrc-4.0b2
PKGNAME=		${DISTNAME:S/src//}
PKGREVISION=		7
CATEGORIES=		mbone
MASTER_SITES=		ftp://ftp.ee.lbl.gov/conferencing/vat/alpha-test/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ee.lbl.gov/vat/
COMMENT=		The Visual Audio Tool - multicast audioconferencing

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX:Q} --with-tk=${PREFIX:Q}

USE_LANGUAGES=		c c++

CPPFLAGS+=		-I${LOCALBASE}/include -I${LOCALBASE}/include/gsm

INSTALL_TARGET=		install install-man

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../audio/gsm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
