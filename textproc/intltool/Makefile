# $NetBSD: Makefile,v 1.17 2004/06/27 17:27:12 jmmv Exp $
#

DISTNAME=		intltool-0.31
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.31/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools-[0-9]*

AUTOMAKE_REQD=		1.4
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		PERL=${PERL5}

pre-configure:
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
