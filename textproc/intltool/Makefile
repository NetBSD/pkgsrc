# $NetBSD: Makefile,v 1.4 2002/12/05 12:05:51 jmmv Exp $
#

DISTNAME=		intltool-0.18
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.18/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

CONFLICTS+=		xml-i18n-tools-[0-9]*

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
