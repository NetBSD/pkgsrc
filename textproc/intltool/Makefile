# $NetBSD: Makefile,v 1.15 2004/02/11 00:48:58 xtraeme Exp $
#

DISTNAME=		intltool-0.30
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

DEPENDS=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

CONFLICTS=		xml-i18n-tools<=0.9

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		PERL=${PERL5}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
