# $NetBSD: Makefile,v 1.13 2004/01/24 15:13:20 grant Exp $
#

DISTNAME=		intltool-0.28
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.28/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools<=0.9

USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
