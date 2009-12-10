# $NetBSD: Makefile,v 1.6 2009/12/10 23:53:00 abs Exp $
#

DISTNAME=	dirsize-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://plasmasturm.org/code/dirsize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plasmasturm.org/code/dirsize/
COMMENT=	Outputs aggregate size of all files in one or more directories

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../mk/bsd.pkg.mk"
