# $NetBSD: Makefile,v 1.65 2023/08/14 05:25:18 wiz Exp $

# Current stable is 2.0.5 (which supports python3)
DISTNAME=	rdiff-backup-1.2.8
PKGREVISION=	13
CATEGORIES=	sysutils net
# Now https://github.com/rdiff-backup/rdiff-backup
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://rdiff-backup.net/
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
