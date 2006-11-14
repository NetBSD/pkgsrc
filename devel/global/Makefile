# $NetBSD: Makefile,v 1.23 2006/11/14 14:14:52 obache Exp $
#

DISTNAME=	global-5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/} \
		http://tamacom.com/global/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output

PKG_INSTALLATION_TYPES=	overwrite pkgviews
GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		perl:run

.include "../../mk/bsd.pkg.mk"
