# $NetBSD: Makefile,v 1.62 2022/06/30 11:18:51 nia Exp $

DISTNAME=	rdiff-backup-1.2.8
PKGREVISION=	12
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.8

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e "s|share/man|${PKGMANDIR}|"
SUBST_MESSAGE.path=	Fixing path to manpages.

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples.html \
		${DESTDIR}${PREFIX}/share/doc/${DISTNAME}

.include "../../net/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
