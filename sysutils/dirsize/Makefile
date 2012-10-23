# $NetBSD: Makefile,v 1.7 2012/10/23 19:50:58 asau Exp $
#

DISTNAME=	dirsize-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://plasmasturm.org/code/dirsize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plasmasturm.org/code/dirsize/
COMMENT=	Outputs aggregate size of all files in one or more directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../mk/bsd.pkg.mk"
