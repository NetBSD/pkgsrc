# $NetBSD: Makefile,v 1.14 2006/02/19 00:41:49 wiz Exp $
#

DISTNAME=		mess822-0.58
PKGREVISION=		1
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

INSTALLATION_DIRS=	bin include lib man man/cat1 man/cat3 man/cat5 man/cat8
INSTALLATION_DIRS+=	man/man1 man/man3 man/man5 man/man8 share/examples/mess822

SUBST_FILES.djbware+=	cdb_seek.c leapsecs_read.c

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
