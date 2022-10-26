# $NetBSD: Makefile,v 1.63 2022/10/26 22:31:44 gdt Exp $

# Current stable is 2.0.5 (which supports python3)
DISTNAME=	rdiff-backup-1.2.8
PKGREVISION=	12
CATEGORIES=	sysutils net
# Apparently moved to https://github.com/rdiff-backup/rdiff-backup
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	snj@NetBSD.org
# Apparently now https://rdiff-backup.net/.
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
