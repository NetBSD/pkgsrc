# $NetBSD: Makefile,v 1.46 2014/05/09 07:37:20 wiz Exp $

DISTNAME=	rdiff-backup-1.2.8
PKGREVISION=	6
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 1.2.8
EGG_NAME=	${DISTNAME:S/-/_/}

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
.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
