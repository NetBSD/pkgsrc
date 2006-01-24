# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:37 wiz Exp $
#

DISTNAME=	iso-codes_0.48-1
PKGNAME=	${DISTNAME:S/_/-/:S/-1//}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/iso-codes/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/pkg-isocodes/
COMMENT=	List of country, language and currency names

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKGCONFIG_OVERRIDE=	iso-codes.pc.in

PYTHON_PATCH_SCRIPTS=	*.py */*.py
REPLACE_PERL=		tab2h.pl

PYTHON_FOR_BUILD_ONLY=		yes
BUILDLINK_DEPMETHOD.perl5=	build
BUILDLINK_DEPMETHOD.py-xml=	build
BUILDLINK_DEPMETHOD.gettext=	build
BUILD_USES_MSGFMT=		yes

pre-configure:
	${TOUCH} ${WRKSRC}/AUTHORS
	${TOUCH} ${WRKSRC}/NEWS
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
