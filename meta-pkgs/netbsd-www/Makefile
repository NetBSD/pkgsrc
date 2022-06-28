# $NetBSD: Makefile,v 1.42 2022/06/28 11:34:46 wiz Exp $

DISTNAME=	netbsd-www-1.10
PKGREVISION=	5
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
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	netbsd-doc-print>=1.4:../../meta-pkgs/netbsd-doc-print
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	psutils>=1.17:../../print/psutils
DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev
DEPENDS+=	w3m>=0.4:../../www/w3m
DEPENDS+=	xplanet>=1.2.0nb3:../../x11/xplanet

USE_TOOLS+=	perl:run ps2pdf:run

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
