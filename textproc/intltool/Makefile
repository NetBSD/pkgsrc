# $NetBSD: Makefile,v 1.11 2003/12/03 02:27:11 xtraeme Exp $
#

DISTNAME=		intltool-0.27.2
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/intltool/0.27/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

CONFLICTS=		xml-i18n-tools<=0.9

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
