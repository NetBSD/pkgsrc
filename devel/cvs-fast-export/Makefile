# $NetBSD: Makefile,v 1.7 2014/05/17 16:10:42 wiz Exp $
#

DISTNAME=	cvs-fast-export-1.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON+=	cvssync

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
