# $NetBSD: Makefile,v 1.11 2004/02/14 17:21:52 jlam Exp $
#

DISTNAME=		fam-2.6.10
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/fam
CONF_FILES=		${EGDIR}/fam.conf ${PKG_SYSCONFDIR}/fam.conf

.include "../../mk/bsd.pkg.mk"
