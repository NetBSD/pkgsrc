# $NetBSD: Makefile,v 1.23 2007/12/19 12:27:29 rillig Exp $
#

DISTNAME=	netbsd-www-1.4
PKGREVISION=	3
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

PKG_DESTDIR_SUPPORT=	user-destdir

# we add an explicit dependency on docbook-xsl here since earlier versions
# generated slightly different html code, leading to a large number of
# unneccessary 'regen' commits
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	docbook-website>=2.6.0nb1:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	xplanet>=1.2.0nb3:../../x11/xplanet
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	psutils>=1.17:../../print/psutils
DEPENDS+=	w3m>=0.4:../../www/w3m
USE_TOOLS+=	perl:run

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
