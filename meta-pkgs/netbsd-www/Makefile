# $NetBSD: Makefile,v 1.45 2023/06/13 18:24:45 wiz Exp $

DISTNAME=	netbsd-www-1.11
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
DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils
DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev
DEPENDS+=	w3m>=0.4:../../www/w3m
DEPENDS+=	xplanet>=1.2.0nb3:../../x11/xplanet

USE_TOOLS+=	perl:run ps2pdf:run

META_PACKAGE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
