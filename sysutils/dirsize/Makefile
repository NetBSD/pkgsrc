# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:57 wiz Exp $
#

DISTNAME=	dirsize-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://plasmasturm.org/code/dirsize/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plasmasturm.org/code/dirsize/
COMMENT=	Outputs aggregate size of all files in one or more directories

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../mk/bsd.pkg.mk"
