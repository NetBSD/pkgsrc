# $NetBSD: Makefile,v 1.9 2006/09/16 14:45:42 jmmv Exp $
#

DISTNAME=	iso-codes_0.53.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/iso-codes/}

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
