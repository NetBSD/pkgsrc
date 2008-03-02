# $NetBSD: Makefile,v 1.20 2008/03/02 06:10:31 jlam Exp $

DISTNAME=	festlex_POSLEX
PKGNAME=	festlex-poslex-1.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	English lexicon suitable for use with Festival

DEPENDS+=	festival>=1.4.0:../../audio/festival

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
