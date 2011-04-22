# $NetBSD: Makefile,v 1.54 2011/04/22 13:44:50 obache Exp $
#

DISTNAME=		intltool-0.40.6
PKGREVISION=		1
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.40/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-XML-Parser>=2.34nb4:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools-[0-9]*

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES
CHECK_INTERPRETER_SKIP=	share/intltool/*.in
TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
