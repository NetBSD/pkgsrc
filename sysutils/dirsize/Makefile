# $NetBSD: Makefile,v 1.4 2006/11/28 16:42:05 tv Exp $
#

DISTNAME=	dirsize-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://plasmasturm.org/code/dirsize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plasmasturm.org/code/dirsize/
COMMENT=	Outputs aggregate size of all files in one or more directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../mk/bsd.pkg.mk"
