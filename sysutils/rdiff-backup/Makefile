# $NetBSD: Makefile,v 1.44 2012/10/23 19:51:21 asau Exp $

DISTNAME=	rdiff-backup-1.2.8
PKGREVISION=	5
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes


SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e "s|share/man|${PKGMANDIR}|"
SUBST_MESSAGE.path=	Fixing path to manpages.

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples.html \
		${DESTDIR}${PREFIX}/share/doc/${DISTNAME}

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
