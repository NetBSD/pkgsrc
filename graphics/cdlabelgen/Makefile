# $NetBSD: Makefile,v 1.2 1999/04/09 21:11:13 hubertf Exp $
#

DISTNAME=		cdlabelgen-1.1.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.red-bean.com/~bwf/software/cdlabelgen/ \
			ftp://ftp.red-bean.com/pub/bwf/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/disk-management

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.red-bean.com/~bwf/software/cdlabelgen/

USE_PERL5=		YES
MAKE_ENV+=		SED="${SED}" MV="${MV}"
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=		INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
