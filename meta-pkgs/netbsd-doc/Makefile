# $NetBSD: Makefile,v 1.17 2007/12/19 12:27:29 rillig Exp $
#

DISTNAME=	netbsd-doc-1.2
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->HTML

DEPENDS+=	opensp>=1.4:../../textproc/opensp
DEPENDS+=	jade>=1.2.1nb3:../../textproc/jade
DEPENDS+=	docbook>=4.0:../../textproc/docbook
DEPENDS+=	iso8879>=1986:../../textproc/iso8879
DEPENDS+=	iso12083>=1993:../../textproc/iso12083
DEPENDS+=	dsssl-docbook-modular>=1.54:../../textproc/dsssl-docbook-modular
DEPENDS+=	html>=4.0:../../textproc/html
DEPENDS+=	tidy>=20031002:../../www/tidy

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
