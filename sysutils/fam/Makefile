# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		fam-2.7.0
PKGREVISION=		2
CATEGORIES=		sysutils devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/stable/	\
			ftp://ftp.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oss.sgi.com/projects/fam/
COMMENT=		File Alteration Monitor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -DNDEBUG"

EGDIR=			${PREFIX}/share/examples/fam
CONF_FILES=		${EGDIR}/fam.conf ${PKG_SYSCONFDIR}/fam.conf

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	man/famd.conf.5 man/famd.8
SUBST_SED.paths=	-e 's,/usr/local/etc/,${PKG_SYSCONFDIR}/,g'

.include "../../mk/bsd.pkg.mk"
