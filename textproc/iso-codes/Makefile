# $NetBSD: Makefile,v 1.11 2007/04/09 01:04:20 wiz Exp $
#

DISTNAME=	iso-codes-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://pkg-isocodes.alioth.debian.org/pub/pkg-isocodes/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/pkg-isocodes/
COMMENT=	List of country, language and currency names

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake gmake msgfmt perl
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKGCONFIG_OVERRIDE=	iso-codes.pc.in

PYTHON_PATCH_SCRIPTS=	*.py */*.py
REPLACE_PERL=		tab2h.pl

PYTHON_FOR_BUILD_ONLY=		yes
BUILDLINK_DEPMETHOD.gettext=	build
BUILDLINK_DEPMETHOD.pyxml=	build

pre-configure:
	${TOUCH} ${WRKSRC}/AUTHORS
	${TOUCH} ${WRKSRC}/NEWS
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
