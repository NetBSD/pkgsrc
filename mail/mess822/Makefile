# $NetBSD: Makefile,v 1.17 2009/06/12 18:54:32 rillig Exp $
#

DISTNAME=		mess822-0.58
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/mess822.html
COMMENT=		Library for parsing Internet mail messages

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

USE_TOOLS+=		nroff

# We change conf-home from the default "/usr/local" and don't
# provide compatibilbity symlinks. We also patch hier.c to respect
# PKG_SYSCONFDIR and set reasonable modes on directories under
# ${PREFIX}, and patch strerr_sys.c to build on Mac OS X.
DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EGDIR=			${PREFIX}/share/examples/mess822
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES+=		${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

DJB_BUILD_TARGETS=	install instcheck

AUTO_MKDIRS=		yes

SUBST_FILES.djbware+=	cdb_seek.c leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
