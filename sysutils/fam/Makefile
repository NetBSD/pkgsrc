# $NetBSD: Makefile,v 1.4 2002/12/17 19:43:39 jmmv Exp $
#

DISTNAME=		fam-2.6.9
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
