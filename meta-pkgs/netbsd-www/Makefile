# $NetBSD: Makefile,v 1.17 2006/01/24 07:32:21 wiz Exp $
#

DISTNAME=	netbsd-www-1.4
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

# we add an explicit dependency on docbook-xsl here since earlier versions
# generated slightly different html code, leading to a large number of
# unneccessary 'regen' commits
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	docbook-website>=2.6.0nb1:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	xearth>=1.1:../../x11/xearth
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	w3m>=0.4:../../www/w3m

USE_TOOLS+=	perl:run
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
