# $NetBSD: Makefile,v 1.25.16.1 2012/02/21 02:43:01 sbd Exp $

DISTNAME=	netbsd-www-1.6
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

PKG_DESTDIR_SUPPORT=	user-destdir

# we add an explicit dependency on docbook-xsl here since earlier versions
# generated slightly different html code, leading to a large number of
# unneccessary 'regen' commits
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	docbook-website>=2.6.0nb1:../../textproc/docbook-website
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	psutils>=1.17:../../print/psutils
DEPENDS+=	teTeX-[0-9]*:../../print/teTeX
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	w3m>=0.4:../../www/w3m
DEPENDS+=	xplanet>=1.2.0nb3:../../x11/xplanet

USE_TOOLS+=	perl:run

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
