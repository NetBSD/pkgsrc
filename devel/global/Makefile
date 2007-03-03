# $NetBSD: Makefile,v 1.25 2007/03/03 05:03:26 uebayasi Exp $
#

DISTNAME=	global-5.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/} \
		http://www.tamacom.com/global/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		perl:run

.include "../../mk/bsd.pkg.mk"
