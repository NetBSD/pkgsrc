# $NetBSD: Makefile,v 1.22 2005/02/04 14:21:00 wiz Exp $
#

DISTNAME=		intltool-0.32.1
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools-[0-9]*

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		PERL=${PERL5}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/buildlink3/bsd.builtin.mk"
.if !empty(USE_BUILTIN.gettext:M[Nn][Oo])
DEPENDS+=		gettext>=0.11.5:../../devel/gettext
.endif

.include "../../mk/bsd.pkg.mk"
