# $NetBSD: Makefile,v 1.8 2004/01/24 15:06:57 grant Exp $
#

DISTNAME=		fam-2.6.9
PKGREVISION=		1
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
