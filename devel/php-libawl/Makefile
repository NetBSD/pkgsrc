# $NetBSD: Makefile,v 1.20 2024/07/09 13:55:38 hauke Exp $
#

LIBAWL_VERSION=	0.65
DISTNAME=	libawl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=davical-project/}
GITLAB_PROJECT=	awl
GITLAB_TAG=	a3b9ae16	# v0.65

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://gitlab.com/davical-project/awl
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/awl-${GITLAB_TAG}

USE_TOOLS+=	gmake

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

do-install:
	cd ${WRKSRC}/dba;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done;

	cd ${WRKSRC}/inc;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done;

.include "../../devel/php-libawl/Makefile.common"
.include "../../mk/bsd.pkg.mk"
