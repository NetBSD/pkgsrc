# $NetBSD: Makefile,v 1.15 2020/04/26 13:58:32 rillig Exp $
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
SUBST_FILES.awflib=	awf awf.1
SUBST_SED.awflib+=	-e 's|/usr/lib/awf|${PREFIX}/share/awf|'
SUBST_VARS.awflib=	AWK
SUBST_STAGE.awflib=	pre-configure

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
