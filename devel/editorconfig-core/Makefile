# $NetBSD: Makefile,v 1.2 2017/05/28 19:59:04 nros Exp $
 
DISTNAME=	editorconfig-core-c-0.12.1
PKGNAME=	${DISTNAME:S/c-//}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.sf.net/project/editorconfig/EditorConfig-C-Core/${PKGVERSION}/source/

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.editorconfig.org/
COMMENT=	Editorconfig C library
LICENSE=	2-clause-bsd

USE_CMAKE= 	yes

.include "options.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
