# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:59:49 jlam Exp $
#

DISTNAME=		fam-2.6.7
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_GMAKE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
