# $NetBSD: Makefile,v 1.17 2018/08/22 09:46:15 wiz Exp $
#

DISTNAME=		pslib-0.4.5
PKGREVISION=		3
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pslib.sourceforge.net/
COMMENT=		C-library to create PostScript files
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libps.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt perl gmake

# share/locale/de/LC_MESSAGES/pslib.mo is missing without these
post-build:
	(cd ${WRKSRC}/po; ${GMAKE})

post-install:
	(cd ${WRKSRC}/po; ${GMAKE} install)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
