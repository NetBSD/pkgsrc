# $NetBSD: Makefile,v 1.4 2001/12/04 06:15:01 jlam Exp $
#

DISTNAME=	sed-3.02
PKGNAME=	g${DISTNAME}
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU version of sed

GNU_CONFIGURE=	YES
CONFIGURE_ARGS= --program-prefix=g
INFO_FILES=	sed.info
AUTOMAKE_PATTERNS+=	sed.info version.texi stamp-vti

.include "../../mk/bsd.pkg.mk"
