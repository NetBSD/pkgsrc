# $NetBSD: Makefile,v 1.69 2019/08/11 13:23:24 wiz Exp $

DISTNAME=		intltool-0.51.0
PKGREVISION=		4
CATEGORIES=		textproc devel gnome
MASTER_SITES=		https://launchpad.net/intltool/trunk/${PKGVERSION_NOREV}/+download/
MASTER_SITES+=		http://launchpadlibrarian.net/94524169/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://launchpad.net/intltool/
COMMENT=		Internationalization Tool Collection
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-XML-Parser>=2.34nb4:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools-[0-9]*

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES
CHECK_INTERPRETER_SKIP=	share/intltool/*.in
TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
