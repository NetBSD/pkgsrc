# $NetBSD: Makefile,v 1.5.2.1 2002/06/30 06:24:17 jlam Exp $
#

DISTNAME=	sed-3.02
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU version of sed

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --program-prefix=g
INFO_FILES=	sed.info
AUTOMAKE_PATTERNS+=	sed.info version.texi stamp-vti

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
