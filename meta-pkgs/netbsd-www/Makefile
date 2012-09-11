# $NetBSD: Makefile,v 1.28 2012/09/11 23:26:14 asau Exp $

DISTNAME=	netbsd-www-1.7
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

# we add an explicit dependency on docbook-xsl here since earlier versions
# generated slightly different html code, leading to a large number of
# unneccessary 'regen' commits
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	docbook-website>=2.6.0nb1:../../textproc/docbook-website
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	netbsd-doc-print>=1.3:../../meta-pkgs/netbsd-doc-print
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	psutils>=1.17:../../print/psutils
DEPENDS+=	w3m>=0.4:../../www/w3m
DEPENDS+=	xplanet>=1.2.0nb3:../../x11/xplanet

USE_TOOLS+=	perl:run

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
