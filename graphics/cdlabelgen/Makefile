# $NetBSD: Makefile,v 1.1.1.1 1999/03/30 09:13:11 rh Exp $
#

DISTNAME=		cdlabelgen-1.1.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.red-bean.com/~bwf/software/cdlabelgen/ \
			ftp://ftp.red-bean.com/pub/bwf/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/disk-management

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.red-bean.com/~bwf/software/cdlabelgen/

DEPENDS+=		perl-5.00404:../../lang/perl5

MAKE_ENV+=		SED="${SED}" MV="${MV}"
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=		INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
