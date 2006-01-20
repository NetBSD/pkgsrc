# $NetBSD: Makefile,v 1.30 2006/01/20 16:15:54 jmmv Exp $
#

DISTNAME=		intltool-0.34.1
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.34/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools-[0-9]*

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
