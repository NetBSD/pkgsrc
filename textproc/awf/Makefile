# $NetBSD: Makefile,v 1.13 2013/04/06 12:04:02 rodent Exp $
#

DISTNAME=	nroff-clone
PKGNAME=	awf-19900907
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.scn.rain.com/pub/text/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scn.rain.com/pub/text/
COMMENT=	Text formatter (nroff-clone) written in awk

EXTRACT_CMD=	${GZCAT} $$extract_file | ${SED} -e '1,/^\#!/d' | ${SH}
WRKSRC=		${WRKDIR}

SUBST_CLASSES+=		awflib
SUBST_MESSAGE.awflib=	Fixing awf library path and awk pathname.
SUBST_FILES.awflib=	Makefile awf awf.1
SUBST_SED.awflib+=	-e 's|/usr/lib/awf|${PREFIX}/share/awf|'
SUBST_SED.awflib+=	-e 's|@AWK@|${AWK}|g'
SUBST_STAGE.awflib=	pre-configure

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
